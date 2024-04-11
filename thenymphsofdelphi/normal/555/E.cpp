#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 2e5 + 5, M = 4e5 + 5, LN = 18;

struct disjoint_set_union{
    int par[N];

    disjoint_set_union(){
        memset(par, -1, sizeof(par));
    }

    int root(int x){
        return (par[x] < 0 ? x : (par[x] = root(par[x])));
    }

    void merge(int x, int y){
        if ((x = root(x)) == (y = root(y))){
            return;
        }
        if (par[x] > par[y]){
            swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
    }
} dsu;

struct edge_t{
    int u, v;

    edge_t(){

    }

    edge_t(int u, int v): u(u), v(v){

    }
};

int n, m, q;
edge_t a[M];
vi adj[N];
pii b[N];

int ctrtin, tin[N], low[N];
set <int> sttbridge;

void dfs_tin(int u, int ip = -1){
    tin[u] = low[u] = ++ctrtin;
    Fora(i, adj[u]){
        if ((i ^ 1) == ip){
            continue;
        }
        int v = a[i].v;
        if (!tin[v]){
            dfs_tin(v, i);
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], tin[v]);
        }
    }
    if (low[u] == tin[u]){
        sttbridge.emplace(ip);
        sttbridge.emplace(ip ^ 1);
    }
}

int n2, f[N], n3, g[N];
vi adj2[N];

int par[N][LN], h[N];
bool lazy[N][LN][2];

void dfs2(int u, int p){
    For(i, 1, LN){
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    Fora(v, adj2[u]){
        if (v == p){
            continue;
        }
        g[v] = g[u];
        par[v][0] = u;
        h[v] = h[u] + 1;
        dfs2(v, u);
    }
}

int lca(int u, int v){
    if (h[u] < h[v]){
        swap(u, v);
    }
    FordE(i, LN - 1, 0){
        if (h[u] - (1 << i) >= h[v]){
            u = par[u][i];
        }
    }
    if (u == v){
        return u;
    }
    FordE(i, LN - 1, 0){
        if (par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void update(int u, int v, int j){
    FordE(i, LN - 1, 0){
        if (h[u] - (1 << i) >= h[v]){
            lazy[u][i][j] = 1;
            u = par[u][i];
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m >> q;
    ForE(i, 1, m){
        int u, v; cin >> u >> v;
        a[2 * i - 2] = edge_t(u, v);
        adj[u].emplace_back(2 * i - 2);
        a[2 * i - 1] = edge_t(v, u);
        adj[v].emplace_back(2 * i - 1);
    }
    ForE(i, 1, q){
        cin >> b[i].fi >> b[i].se;
    }

    ForE(u, 1, n){
        if (!tin[u]){
            dfs_tin(u);
        }
    }
    ForE(i, 1, 2 * m){
        if (sttbridge.find(i) == sttbridge.end()){
            dsu.merge(a[i].u, a[i].v);
        }
    }
    ForE(u, 1, n){
        if (f[dsu.root(u)] == 0){
            f[dsu.root(u)] = ++n2;
        }
        f[u] = f[dsu.root(u)];
    }
    Fora(i, sttbridge){
        adj2[f[a[i].u]].emplace_back(f[a[i].v]);
    }
    ForE(u, 1, n2){
        if (g[u] == 0){
            g[u] = ++n3;
            dfs2(u, 0);
        }
    }

    ForE(i, 1, q){
        int u, v; tie(u, v) = b[i];
        u = f[u]; v = f[v];
        if (g[u] != g[v]){
            cout << "No" << endl;
            return 0;
        }
        int t = lca(u, v);
        update(u, t, 0);
        update(v, t, 1);
    }
    FordE(i, LN - 1, 1){
        ForE(u, 1, n2){
            ForE(j, 0, 1){
                if (lazy[u][i][j]){
                    lazy[u][i - 1][j] = lazy[par[u][i - 1]][i - 1][j] = 1;
                }
            }
        }
    }
    ForE(u, 1, n2){
        if (par[u][0] != 0 and lazy[u][0][0] and lazy[u][0][1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
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