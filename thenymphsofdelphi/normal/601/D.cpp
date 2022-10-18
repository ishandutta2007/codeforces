#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = l; i < r; i++)
#define ForE(i, l, r) for (auto i = l; i <= r; i++)
#define FordE(i, l, r) for (auto i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pair <int, int>>;
using vvi = vector <vector <int>>;

const int N = 3e5 + 5;
const pii base = {257, 1009}, mod = {998244853, 1e9 + 9};

inline void sadd(int& x, int y, int mod){
    if ((x += y) >= mod) x -= mod;
    return;
}

inline int add(int x, int y, int mod){
    if ((x += y) >= mod) x -= mod;
    return x;
}

inline void ssub(int& x, int y, int mod){
    if ((x -= y) < 0) x += mod;
    return;
}

inline int sub(int x, int y, int mod){
    if ((x -= y) < 0) x += mod;
    return x;
}

inline int mul(int x, int y, int mod){
    return 1ll * x * y % mod;
}

inline int binpow(int x, int y, int mod){
    int ans = 1;
    while (y){
        if (y & 1) ans = mul(ans, x, mod);
        x = mul(x, x, mod);
        y >>= 1;
    }
    return ans;
}

inline int inv(int x, int mod){
    return binpow(x, mod - 2, mod);
}

#define div __div__
inline int div(int x, int y, int mod){
    return mul(x, binpow(y, mod - 2, mod), mod);
}

int n;
int a[N];
string s;
vi adj[N];

int sz[N], heavy[N];

void dfs_sz(int u, int p){
    sz[u] = 1;
    heavy[u] = -1;
    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        dfs_sz(v, u);
        sz[u] += sz[v];
        if (heavy[u] == -1 or sz[heavy[u]] < sz[v]){
            heavy[u] = v;
        }
    }
}

pii powbase[N];

set <pii> stt;
pii coefx = make_pair(1, 1), coefy = make_pair(0, 0);
int ans[N];

pii f(pii hsh){
    return make_pair(add(mul(hsh.fi, coefx.fi, mod.fi), coefy.fi, mod.fi), add(mul(hsh.se, coefx.se, mod.se), coefy.se, mod.se));
}

pii finv(pii hsh){
    return make_pair(div(sub(hsh.fi, coefy.fi, mod.fi), coefx.fi, mod.fi), div(sub(hsh.se, coefy.se, mod.se), coefx.se, mod.se));
}

void dfs_insert(int u, int p, int h, pii hsh){
    hsh = make_pair(add(hsh.fi, mul(s[u] - 'a' + 1, powbase[h].fi, mod.fi), mod.fi), add(hsh.se, mul(s[u] - 'a' + 1, powbase[h].se, mod.se), mod.se));
    // cout << "INSERT " << u << ' ' << p << ' ' << h << ' ' << hsh.fi << ' ' << hsh.se << ' ' << f(hsh).fi << ' ' << f(hsh).se << endl;
    stt.emplace(finv(hsh));
    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        dfs_insert(v, u, h + 1, hsh);
    }
}

void dfs_mergeset(int u, int p, bool keep = 0){
    Fora(v, adj[u]){
        if (v == p or v == heavy[u]){
            continue;
        }
        dfs_mergeset(v, u);
    }
    if (heavy[u] != -1){
        dfs_mergeset(heavy[u], u, 1);
        coefx = make_pair(mul(coefx.fi, base.fi, mod.fi), mul(coefx.se, base.se, mod.se));
        coefy = make_pair(add(mul(coefy.fi, base.fi, mod.fi), s[u] - 'a' + 1, mod.fi), add(mul(coefy.se, base.se, mod.se), s[u] - 'a' + 1, mod.se));
    }
    Fora(v, adj[u]){
        if (v == p or v == heavy[u]){
            continue;
        }
        dfs_insert(v, u, 1, make_pair(s[u] - 'a' + 1, s[u] - 'a' + 1));
    }
    stt.emplace(finv(make_pair(s[u] - 'a' + 1, s[u] - 'a' + 1)));
    ans[u] = a[u] + isz(stt);
    if (!keep){
        stt.clear();
        coefx = make_pair(1, 1); coefy = make_pair(0, 0);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(u, 1, n){
        cin >> a[u];
    }
    cin >> s; s = ' ' + s;
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dfs_sz(1, 1);
    powbase[0] = make_pair(1, 1);
    For(i, 1, N){
        powbase[i] = make_pair(mul(powbase[i - 1].fi, base.fi, mod.fi), mul(powbase[i - 1].se, base.se, mod.se));
    }
    dfs_mergeset(1, 1);

    int mx = *max_element(ans + 1, ans + n + 1);
    cout << mx << endl << accumulate(ans + 1, ans + n + 1, 0, [&](int sum, int x){
        return sum + (x == mx ? 1 : 0);
    }) << endl;
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/