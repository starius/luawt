/* luawt, Lua bindings for Wt
 * Copyright (c) 2015 Pavel Dolgov and Boris Nagaev
 *
 * See the LICENSE file for terms of use.
 */

#include "globals.hpp"

static const luaL_Reg functions[] = {
    {"WRun", wrap<lua_WRun>::func},
    {NULL, NULL},
};

extern "C" {

int luaopen_luawt(lua_State* L) {
    lua_newtable(L); // module luawt
    my_setfuncs(L, functions);
    lua_pushcfunction(L, lua_shared);
    lua_call(L, 0, 1);
    lua_setfield(L, -2, "shared");
    return 1;
}

}