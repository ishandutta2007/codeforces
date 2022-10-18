#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e5 + 5e4 + 7, S = sqrt(2 * N) + 2, mod = 998244353;

inline void sadd(int& x, int y){
    if ((x += y) >= mod) x -= mod;
    return;
}

inline int add(int x, int y){
    if ((x += y) >= mod) x -= mod;
    return x;
}

inline void ssub(int& x, int y){
    if ((x -= y) < 0) x += mod;
    return;
}

inline int sub(int x, int y){
    if ((x -= y) < 0) x += mod;
    return x;
}

inline int mul(int x, int y){
    return 1ll * x * y % mod;
}

inline int binpow(int x, int y){
    int ans = 1;
    while (y){
        if (y & 1) ans = mul(ans, x);
        x = mul(x, x);
        y >>= 1;
    }
    return ans;
}

inline int inv(int x){
    return binpow(x, mod - 2);
}

#define div __div__
inline int div(int x, int y){
    return mul(x, binpow(y, mod - 2));
}

int fac[N], invfac[N];

void calfac(){
    fac[0] = invfac[0] = 1;
    For(i, 1, N){
        fac[i] = mul(fac[i - 1], i);
    }
    invfac[N - 1] = binpow(fac[N - 1], mod - 2);
    FordE(i, N - 2, 1){
        invfac[i] = mul(invfac[i + 1], i + 1);
    }
}

inline int C(int n, int k){
    if (n < 0 or k < 0 or k > n){
        return 0;
    }
    return mul(fac[n], mul(invfac[k], invfac[n - k]));
}

inline int P(int n, int k){
    if (n < 0 or k < 0 or k > n){
        return 0;
    }
    return mul(fac[n], invfac[n - k]);
}

struct fenwick_tree{
    vi bit;
    int n;

    fenwick_tree(int n = 0){
        this->n = n + 1;
        bit.assign(this->n + 1, 0);
    }

    fenwick_tree(vector<int> a) : fenwick_tree(a.size()){
        this->n = a.size() + 1;
        bit.assign(n + 1, 0);
        For(i, 0, a.size()){
            add(i, a[i]);
        }
    }

    int get(int idx){
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx){
            sadd(ans, bit[idx]);
        }
        return ans;
    }

    void update(int l, int r, int delta){
        for (int idx = l; idx <= n; idx += idx & -idx){
            sadd(bit[idx], delta);
        }
        for (int idx = r + 1; idx <= n; idx += idx & -idx){
            ssub(bit[idx], delta);
        }
    }
} bit;

int n, q;
vi adj[N];

int par[N], sz[N];
int ctrtour, tin[N], tout[N];

void dfs_tour(int u, int p){
    par[u] = p; sz[u] = 1;
    ctrtour++; tin[u] = ctrtour;
    Fora(&v, adj[u]){
        if (v == p){
            continue;
        }
        dfs_tour(v, u);
        sz[u] += sz[v];
    }
    tout[u] = ctrtour;
}

int ctrheavy, heavy[2 * N / S + 2], isheavy[N];
int szrem[2 * N / S + 2][N];
vi szstree[N];

void dfs_szrem(int i, int u, int p, int val){
    szrem[i][u] = val;
    Fora(&v, adj[u]){
        if (v == p){
            continue;
        }
        dfs_szrem(i, v, u, val);
    }
}

int valque[2 * N / S + 2];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v); adj[v].emplace_back(u);
    }
    dfs_tour(1, 0);
    ForE(u, 1, n){
        if (isz(adj[u]) >= S){
            heavy[++ctrheavy] = u;
            isheavy[u] = ctrheavy;
        }
    }
    ForE(u, 1, n){
        Fora(&v, adj[u]){
            if (v == par[u]){
                szstree[u].emplace_back(sz[u]);
            }
            else{
                szstree[u].emplace_back(n - sz[v]);
            }
        }
        if (isheavy[u]){
            For(i, 0, isz(adj[u])){
                dfs_szrem(isheavy[u], adj[u][i], u, szstree[u][i]);
            }
            szrem[isheavy[u]][u] = n;
        }
    }
    bit = fenwick_tree(n);
    while (q--){
        int que; cin >> que;
        if (que == 1){
            int u, d; cin >> u >> d; d = div(d, n);
            if (isheavy[u]){
                sadd(valque[isheavy[u]], d);
            }
            else{
                For(i, 0, isz(adj[u])){
                    int v = adj[u][i];
                    if (v == par[u]){
                        bit.update(1, n, mul(d, szstree[u][i]));
                        bit.update(tin[u], tout[u], sub(0, mul(d, szstree[u][i])));
                    }
                    else{
                        bit.update(tin[v], tout[v], mul(d, szstree[u][i]));
                    }
                }
                bit.update(tin[u], tin[u], mul(d, n));
            }
        }
        else{
            int u; cin >> u;
            int ans = bit.get(tin[u]);
            ForE(i, 1, ctrheavy){
                sadd(ans, mul(valque[i], szrem[i][u]));
            }
            cout << ans << endl;
        }
    }
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