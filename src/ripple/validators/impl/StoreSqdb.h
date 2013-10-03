//------------------------------------------------------------------------------
/*
    This file is part of rippled: https://github.com/ripple/rippled
    Copyright (c) 2012, 2013 Ripple Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#ifndef RIPPLE_VALIDATORS_STORESQDB_H_INCLUDED
#define RIPPLE_VALIDATORS_STORESQDB_H_INCLUDED

namespace ripple {
namespace Validators {

/** Database persistence for Validators using SQLite */
class StoreSqdb
    : public Store
    , public LeakChecked <StoreSqdb>
{
public:
    explicit StoreSqdb (Journal journal = Journal());

    ~StoreSqdb ();

    Error open (File const& file);

    void insert (SourceDesc& desc);

    void update (SourceDesc& desc, bool updateFetchResults);

private:
    void report (Error const& error, char const* fileName, int lineNumber);

    bool select (SourceDesc& desc);
    void selectList (SourceDesc& desc);

    Error init ();

    Journal m_journal;
    sqdb::session m_session;
};

}
}

#endif
