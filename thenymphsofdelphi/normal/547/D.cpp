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

const int N = 2e5 + 5;

struct Eulerian_Graph_Undir{
    struct Edge{
        int u, v;
        bool reach;
        
        Edge(int u, int v, bool reach): u(u), v(v), reach(reach) {
            
        }
    };
    
    int n;
    vector <Edge> edges;
    vvi adj;
    vi deg, ptr;
    
    Eulerian_Graph_Undir(int n = 0): n(n) {
        adj.resize(n + 1);
        deg.resize(n + 1);
        ptr.resize(n + 1);
    }

    void Add_Edge(int u, int v){
        edges.push_back(Edge(u, v, 0));
        edges.push_back(Edge(v, u, 0));
        adj[u].push_back(isz(edges) - 2);
        adj[v].push_back(isz(edges) - 1);
        deg[u]++; deg[v]++;
    }

    void Dfs_Eulerian_Undir(int u, vi& path){
        while (ptr[u] < isz(adj[u])){
            ptr[u]++;
            int i = adj[u][ptr[u] - 1];
            if (edges[i].reach){
                continue;
            }
            edges[i].reach = 1;
            edges[i ^ 1].reach = 1;
            Dfs_Eulerian_Undir(edges[i].v, path);
        }
        path.push_back(u);
        return;
    }

    bool Eulerian_Cycle(vi& path){
        ForE(i, 1, n){
            if (deg[i] % 2){
                return 0;
            }
        }
        ForE(i, 1, n){
            if (isz(adj[i])){
                Dfs_Eulerian_Undir(i, path);
                break;
            }
        }
        ForE(i, 1, n){
            if (ptr[i] != isz(adj[i])){
                return 0;
            }
        }
        reverse(bend(path));
        return 1;
    }

    bool Eulerian_Path(vi& path){
        int pathbegin = -1, pathend = -1;
        ForE(i, 1, n){
            if (deg[i] % 2){
                if (pathbegin == -1){
                    pathbegin = i;
                    continue;
                }
                if (pathend == -1){
                    pathend = i;
                    continue;
                }
                return 0;
            }
        }
        if (pathbegin != -1){
            Add_Edge(pathend, pathbegin);
        }
        if (!Eulerian_Cycle(path)){
            return 0;
        }
        if (pathbegin != -1){
            edges.pop_back();
            edges.pop_back();
            adj[pathend].pop_back();
            adj[pathbegin].pop_back();
            deg[pathend]--; deg[pathbegin]--;
            ptr[pathend]--; ptr[pathbegin]--;
            path.pop_back();
            For(i, 0, isz(path) - 1){
                if (path[i] == pathend && path[i + 1] == pathbegin){
                    rotate(path.begin(), path.begin() + i + 1, path.end());
                    break;
                }
            }
        }
        ForE(i, 1, n){
            if (ptr[i] != isz(adj[i])){
                return 0;
            }
        }
        return 1;
    }
} cac;

int n, m = 2e5;
int x[N], y[N];

vi adj[2 * N];
int vis[2 * N];
int ctridx, idx[2 * N], revidx[2 * N];
vi vodddeg;

map <pii, int> mppxy;

int ans[N];

void dfs1(int u){
    vis[u] = 1;
    idx[u] = ++ctridx;
    revidx[ctridx] = u;
    if (isz(adj[u]) & 1){
        vodddeg.emplace_back(u);
    }
    Fora(&v, adj[u]){
        if (vis[v] != 1){
            dfs1(v);
        }
    }
}

void dfs2(int u){
    vis[u] = 2;
    Fora(&v, adj[u]){
        if (v > u){
            cac.Add_Edge(idx[u], idx[v]);
        }
        if (vis[v] != 2){
            dfs2(v);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> x[i] >> y[i];
    }
    ForE(i, 1, n){
        adj[x[i]].emplace_back(y[i] + m);
        adj[y[i] + m].emplace_back(x[i]);
        mppxy[make_pair(x[i], y[i] + m)] = i;
        mppxy[make_pair(y[i] + m, x[i])] = i;
    }
    ForE(i, 1, 2 * m){
        if (isz(adj[i]) and !idx[i]){
            ctridx = 1;
            idx[2 * m + 1] = 1;
            revidx[1] = 2 * m + 1;
            vodddeg.clear();
            dfs1(i);
            cac = Eulerian_Graph_Undir(ctridx);
            dfs2(i);
            set <pii> sttedge;
            for (int j = 1; j < isz(vodddeg); j += 2){
                bool isx = vodddeg[j - 1] <= m, isy = vodddeg[j] <= m;
                if (isx ^ isy){
                    cac.Add_Edge(idx[vodddeg[j - 1]], idx[vodddeg[j]]);
                    sttedge.insert(make_pair(vodddeg[j - 1], vodddeg[j]));
                    sttedge.insert(make_pair(vodddeg[j], vodddeg[j - 1]));
                }
                else{
                    cac.Add_Edge(idx[vodddeg[j - 1]], 1);
                    cac.Add_Edge(1, idx[vodddeg[j]]);
                    sttedge.insert(make_pair(vodddeg[j - 1], 2 * m + 1));
                    sttedge.insert(make_pair(2 * m + 1, vodddeg[j - 1]));
                    sttedge.insert(make_pair(2 * m + 1, vodddeg[j]));
                    sttedge.insert(make_pair(vodddeg[j], 2 * m + 1));
                }
            }
            vi path;
            assert(cac.Eulerian_Cycle(path));
            For(j, 1, isz(path)){
                if (sttedge.find(make_pair(revidx[path[j - 1]], revidx[path[j]])) == sttedge.end()){
                    ans[mppxy[make_pair(revidx[path[j - 1]], revidx[path[j]])]] = j & 1;
                }
                else{
                    sttedge.erase(make_pair(revidx[path[j - 1]], revidx[path[j]]));
                    sttedge.erase(make_pair(revidx[path[j]], revidx[path[j - 1]]));
                }
            }
            assert(sttedge.empty());
        }
    }
    ForE(i, 1, n){
        if (ans[i]){
            cout << 'r';
        }
        else{
            cout << 'b';
        }
    } cout << endl;
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