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

const int N = 2e5 + 5, M = 128 * 128;

struct Eulerian_Graph_Dir{
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
    
    Eulerian_Graph_Dir(int n = 0): n(n) {
        adj.resize(n + 1);
        deg.resize(n + 1);
        ptr.resize(n + 1);
    }

    void Add_Edge(int u, int v){
        edges.push_back(Edge(u, v, 0));
        adj[u].push_back(isz(edges) - 1);
        deg[u]--; deg[v]++;
    }

    void Dfs_Eulerian_Dir(int u, vi& path){
        while (ptr[u] < isz(adj[u])){
            ptr[u]++;
            int i = adj[u][ptr[u] - 1];
            if (edges[i].reach){
                continue;
            }
            edges[i].reach = 1;
            Dfs_Eulerian_Dir(edges[i].v, path);
        }
        path.push_back(u);
        return;
    }

    bool Eulerian_Cycle(vi& path){
        ForE(i, 1, n){
            if (deg[i]){
                return 0;
            }
        }
        ForE(i, 1, n){
            if (isz(adj[i])){
                Dfs_Eulerian_Dir(i, path);
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
            if (deg[i] < -1 || deg[i] > 1){
                return 0;
            }
            if (deg[i] == -1){
                if (pathbegin != -1){
                    return 0;
                }
                pathbegin = i;
            }
            if (deg[i] == 1){
                if (pathend != -1){
                    return 0;
                }
                pathend = i;
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
            adj[pathend].pop_back();
            deg[pathend]++; deg[pathbegin]--;
            ptr[pathend]--;
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
} cac(M);

int n;
string s[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        string s; cin >> s;
        int u = s[0] * 128 + s[1], v = s[1] * 128 + s[2];
        cac.Add_Edge(u, v);
    }
    vi path;
    if (cac.Eulerian_Path(path)){
        cout << "YES" << endl;
        cout << (char)(path[0] / 128);
        Fora(&v, path){
            cout << (char)(v % 128);
        }
        cout << endl;
    }
    else{
        cout << "NO" << endl;
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