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

const int N = 2e5 + 5;

struct DisjointSetUnion{
    int par[N];

    DisjointSetUnion(){
        memset(par, -1, sizeof(par));
    }

    int root(int x){
        return par[x] < 0 ? x : (par[x] = root(par[x]));
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
} dsu, dsu2;

struct Edge{
    int u, v, w;

    Edge(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w){

    }
};

bool operator< (const Edge& lhs, const Edge& rhs){
    return lhs.w < rhs.w;
}

int n, m, xsum; ll num0, ans;
set <pii> sttedges;
set <int> nvisited;
int node[N]; vector <Edge> edges;

void dfs1(int u){
    vi nxt;
    Fora(&v, nvisited){
        if (sttedges.find(make_pair(u, v)) == sttedges.end()){
            nxt.emplace_back(v);
        }
    }
    Fora(&v, nxt){
        assert(nvisited.find(v) != nvisited.end());
        nvisited.erase(v);
    }
    Fora(&v, nxt){
        num0--;
        dsu.merge(u, v);
        dfs1(v);
    }
}

signed main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        int u, v, w; cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
        sttedges.insert(make_pair(u, v)); sttedges.insert(make_pair(v, u));
        xsum ^= w;
    }
    sort(bend(edges));
    num0 = (ll)n * (n - 1) / 2 - m;
    ForE(i, 1, n){
        nvisited.insert(i);
    }
    ForE(i, 1, n){
        if (nvisited.find(i) != nvisited.end()){
            nvisited.erase(i);
            dfs1(i);
        }
    }
    if (num0){
        xsum = 0;
    }
    For(i, 0, isz(edges)){
        if (dsu.root(edges[i].u) != dsu.root(edges[i].v)){
            ans += edges[i].w;
            dsu.merge(edges[i].u, edges[i].v);
            dsu2.merge(edges[i].u, edges[i].v);
        }
        if (dsu2.root(edges[i].u) != dsu2.root(edges[i].v)){
            xsum = min(xsum, edges[i].w);
        }
    }
    ans += xsum;
    cout << ans << endl;
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
*/