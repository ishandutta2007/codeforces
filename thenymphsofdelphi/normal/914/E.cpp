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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 2e5 + 5, M = 19, K = 20;

int n;
vi adj[N];
string s;

vi adj_cent[N]; int root_cent, par_cent[N];
bool ck_decomp[N];
int sz[N];

void dfs_cent(int u, int p){
    sz[u] = 1;
    Fora(&v, adj[u]){
        if (v == p or ck_decomp[v]){
            continue;
        }
        dfs_cent(v, u);
        sz[u] += sz[v];
    }
}

int decompose_cent(int u){
    int p = u;
    dfs_cent(u, p);
    int szu = sz[u];
    while (1){
        int nu = -1;
        Fora(&v, adj[u]){
            if (v == p or ck_decomp[v]){
                continue;
            }
            if (sz[v] * 2 > szu){
                nu = v;
                break;
            }
        }
        if (nu != -1){
            p = u; u = nu;
            continue;
        }
        ck_decomp[u] = 1;
        Fora(&v, adj[u]){
            if (ck_decomp[v]){
                continue;
            }
            int cv = decompose_cent(v);
            adj_cent[u].push_back(cv);
            par_cent[cv] = u;
        }
        return u;
    }
}

int h[N];
pii sparse[M][2 * N];
int ctrtim; pii tim[N];

void dfs_lca(int u, int p){
    h[u] = h[p] + 1;
    tim[u].fi = ++ctrtim;
    sparse[0][ctrtim] = make_pair(h[u], u);
    Fora(&v, adj[u]){
        if (v == p){
            continue;
        }
        sparse[0][++ctrtim] = make_pair(h[u], u);
        dfs_lca(v, u);
    }
    tim[u].se = ctrtim;
}

void init_lca(){
    dfs_lca(1, 1);
    For(j, 1, M){
        ForE(i, 1, ctrtim - (1 << j) + 1){
            sparse[j][i] = min(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);
        }
    }
}

int lca(int u, int v){
    int l = min(tim[u].fi, tim[v].fi), r = max(tim[u].se, tim[v].se);
    int z = __builtin_clz(r - l + 1) ^ 31;
    return min(sparse[z][l], sparse[z][r - (1 << z) + 1]).se;
}

int msk[N];

void dfs_msk(int u, int p){
    msk[u] = msk[p] ^ (1 << (s[u] - 'a'));
    Fora(&v, adj[u]){
        if (v == p){
            continue;
        }
        dfs_msk(v, u);
    }
}

int cal_msk(int u, int v){
    return msk[u] ^ msk[v] ^ (1 << (s[lca(u, v)] - 'a'));
}

ll ans[N], tans[N];
int cnt[1 << K];

void dfs_resettans(int u, int p){
    tans[u] = 0;
    Fora(&v, adj[u]){
        if (v == p or ck_decomp[v]){
            continue;
        }
        dfs_resettans(v, u);
    }
}

void dfs_cnt(int u, int p, int root, int delta){
    cnt[cal_msk(u, root)] += delta;
    Fora(&v, adj[u]){
        if (v == p or ck_decomp[v]){
            continue;
        }
        dfs_cnt(v, u, root, delta);
    }
}

void dfs_tans(int u, int p, int root){
    int mask = cal_msk(u, root);
    if (__builtin_popcount(mask) <= 1){
        tans[u]++;
        tans[root]++;
    }
    mask ^= (1 << (s[root] - 'a'));
    tans[u] += cnt[mask];
    For(i, 0, 20){
        tans[u] += cnt[mask ^ (1 << i)];
    }
    Fora(&v, adj[u]){
        if (v == p or ck_decomp[v]){
            continue;
        }
        dfs_tans(v, u, root);
    }
}

void dfs_updans(int u, int p, int root){
    Fora(&v, adj[u]){
        if (v == p or ck_decomp[v]){
            continue;
        }
        dfs_updans(v, u, root);
        tans[u] += tans[v];
    }
    if (u == root){
        tans[u] /= 2;
    }
    ans[u] += tans[u];
}

void dfs_calans(int u){
    dfs_resettans(u, u);
    Fora(&v, adj[u]){
        if (ck_decomp[v]){
            continue;
        }
        dfs_cnt(v, u, u, 1);
    }
    tans[u] += 2;
    Fora(&v, adj[u]){
        if (ck_decomp[v]){
            continue;
        }
        dfs_cnt(v, u, u, -1);
        dfs_tans(v, u, u);
        dfs_cnt(v, u, u, 1);
    }
    Fora(&v, adj[u]){
        if (ck_decomp[v]){
            continue;
        }
        dfs_cnt(v, u, u, -1);
    }
    dfs_updans(u, u, u);
    ck_decomp[u] = 1;
    Fora(&v, adj_cent[u]){
        dfs_calans(v);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    cin >> s; s = ' ' + s;
    root_cent = decompose_cent(1);
    init_lca();
    dfs_msk(1, 1);
    memset(ck_decomp, 0, sizeof(ck_decomp));
    dfs_calans(root_cent);
    ForE(i, 1, n){
        cout << ans[i] << ' ';
    } cout << endl;
}

/*
==================================================+
INPUT                                             |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/