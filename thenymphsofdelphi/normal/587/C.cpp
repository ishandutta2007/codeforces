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

const int N = 1e5 + 5, M = 17, K = 10;

int n, m, q;
vi adj[N];
vi a[N];
int h[N], lift[N][M][K], par[N][M];
int cac[2 * K];

void dfs(int u, int p){
    h[u] = h[p] + 1;
    par[u][0] = p;
    For(j, 1, M){
        par[u][j] = par[par[u][j - 1]][j - 1];
    }
    For(i, 0, isz(a[u])){
        lift[u][0][i] = a[u][i];
    }
    For(i, isz(a[u]), K){
        lift[u][0][i] = N;
    }
    For(j, 1, M){
        For(i, 0, K){
            cac[i] = lift[u][j - 1][i];
        }
        For(i, K, 2 * K){
            cac[i] = lift[par[u][j - 1]][j - 1][i - K];
        }
        sort(cac, cac + 2 * K);
        For(i, 0, K){
            lift[u][j][i] = cac[i];
        }
    }
    Fora(&v, adj[u]){
        if (v == p){
            continue;
        }
        dfs(v, u);
    }
}

int lca(int u, int v){
    if (h[u] < h[v]){
        swap(u, v);
    }
    FordE(j, M - 1, 0){
        if (h[u] - (1 << j) >= h[v]){
            u = par[u][j];
        }
    }
    if (u == v){
        return u;
    }
    FordE(j, M - 1, 0){
        if (par[u][j] != par[v][j]){
            u = par[u][j]; v = par[v][j];
        }
    }
    return par[u][0];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m >> q;
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ForE(i, 1, m){
        int u; cin >> u;
        a[u].push_back(i);
    }
    ForE(i, 1, n){
        sort(bend(a[i]));
        if (isz(a[i]) > K){
            a[i].resize(K);
        }
    }
    dfs(1, 0);
    while (q--){
        int u, v, x; cin >> u >> v >> x;
        int w = lca(u, v);
        vi cac2;
        FordE(j, M - 1, 0){
            if (h[u] - (1 << j) >= h[w] - 1){
                For(i, 0, K){
                    cac2.push_back(lift[u][j][i]);
                }
                u = par[u][j];
            }
        }
        FordE(j, M - 1, 0){
            if (h[v] - (1 << j) >= h[w]){
                For(i, 0, K){
                    cac2.push_back(lift[v][j][i]);
                }
                v = par[v][j];
            }
        }
        sort(bend(cac2));
        if (isz(cac2) > x){
            cac2.resize(x);
        }
        while (isz(cac2) and cac2.back() == N){
            cac2.pop_back();
        }
        cout << isz(cac2) << ' ';
        Fora(&v, cac2) cout << v << ' ';
        cout << endl;
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