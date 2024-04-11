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

const int N = 2e5 + 5, M = 18;

struct Edge{
    int u, v, w, id;
    
    Edge(int u = 0, int v = 0, int w = 0, int id = 0): u(u), v(v), w(w), id(id){
        
    }
};

bool operator< (const Edge& lhs, const Edge& rhs){
    return lhs.w < rhs.w;
}

struct DisjointSetUnion{
    int par[N];
    
    DisjointSetUnion(){
        memset(par, -1, sizeof(par));
    }
    
    int root(int x){
        return par[x] < 0 ? x : (par[x] = root(par[x]));
    }
    
    bool merge(int x, int y){
        if ((x = root(x)) == (y = root(y))){
            return 0;
        }
        if (par[x] > par[y]){
            swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
        return 1;
    }
} dsu;

int n, m; ll mstorig;
Edge edges[N];
vpii adj[N];

int h[N], lift[N][M], mx[N][M];

void dfs(int u, int p, int w = 0){
    h[u] = h[p] + 1;
    lift[u][0] = p;
    mx[u][0] = w;
    For(i, 1, M){
        lift[u][i] = lift[lift[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[lift[u][i - 1]][i - 1]);
    }
    Fora(&edge, adj[u]){
        if (edge.fi == p){
            continue;
        }
        dfs(edge.fi, u, edge.se);
    }
}

ll ans[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ForE(i, 1, m){
        cin >> edges[i].u >> edges[i].v >> edges[i].w; edges[i].id = i;
    }
    sort(edges + 1, edges + 1 + m);
    ForE(i, 1, m){
        if (dsu.merge(edges[i].u, edges[i].v)){
            mstorig += edges[i].w;
            adj[edges[i].u].emplace_back(edges[i].v, edges[i].w);
            adj[edges[i].v].emplace_back(edges[i].u, edges[i].w);
        }
    }
    dfs(1, 1);
    ForE(i, 1, m){
        ans[edges[i].id] = mstorig + edges[i].w;
        int mxedge = 0;
        if (h[edges[i].u] < h[edges[i].v]){
            swap(edges[i].u, edges[i].v);
        }
        FordE(j, M - 1, 0){
            if (h[edges[i].u] - (1 << j) >= h[edges[i].v]){
                mxedge = max(mxedge, mx[edges[i].u][j]);
                edges[i].u = lift[edges[i].u][j];
            }
        }
        if (edges[i].u == edges[i].v){
            ans[edges[i].id] -= mxedge;
            continue;
        }
        FordE(j, M - 1, 0){
            if (lift[edges[i].u][j] != lift[edges[i].v][j]){
                mxedge = max(mxedge, mx[edges[i].u][j]);
                mxedge = max(mxedge, mx[edges[i].v][j]);
                edges[i].u = lift[edges[i].u][j];
                edges[i].v = lift[edges[i].v][j];
            }
        }
        mxedge = max(mxedge, mx[edges[i].u][0]);
        mxedge = max(mxedge, mx[edges[i].v][0]);
        ans[edges[i].id] -= mxedge;
    }
    ForE(i, 1, m){
        cout << ans[i] << endl;
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