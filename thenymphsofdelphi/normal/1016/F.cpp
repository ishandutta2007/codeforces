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

const int N = 3e5 + 5;

int n, q;
vpii adj[N];
int queries[N];

int par[N]; bool inpath[N];
ll dist[N]; int mxdist[N];

void dfs1(int u, int p){
    Fora(&edge, adj[u]){
        if (edge.fi == p){
            continue;
        }
        par[edge.fi] = u;
        dist[edge.fi] = dist[u] + edge.se;
        dfs1(edge.fi, u);
    }
}

int szsubtree;

void dfs2(int u, int p, ll d, int r){
    szsubtree++;
    mxdist[r] = d;
    Fora(&edge, adj[u]){
        if (edge.fi == p or inpath[edge.fi]){
            continue;
        }
        dfs2(edge.fi, u, d + edge.se, r);
    }
}

bool whythefuckthisproblemexist;
ll mxalterdist;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    For(i, 1, n){
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs1(1, 1);
    {
        int u = n;
        while (u != 1){
            inpath[u] = 1;
            u = par[u];
        }
        inpath[u] = 1;
        u = n;
        while (u != 1){
            dfs2(u, u, 0, u);
            if (szsubtree > 2){
                whythefuckthisproblemexist = 1;
            }
            szsubtree = 0;
            u = par[u];
        }
        dfs2(u, u, 0, u);
        if (szsubtree > 2){
            whythefuckthisproblemexist = 1;
        }
        szsubtree = 0;
    }
    if (whythefuckthisproblemexist){
        while (q--){
            int x; cin >> x; cout << dist[n] << endl;
        }
        return 0;
    }
    {
        multiset <ll> mtsdist1;
        mtsdist1.insert((ll)-1e18 - 7);
        int u = par[n];
        while (u != 1){
            mtsdist1.insert(dist[u]);
            if (mxdist[u]){
                mtsdist1.insert(dist[u] + mxdist[u]);
            }
            u = par[u];
        }
        mtsdist1.insert(dist[u]);
        if (mxdist[u]){
            mtsdist1.insert(dist[u] + mxdist[u]);
        }
        u = n;
        while (u != 1){
            if (mxdist[u]){
                mxalterdist = max(mxalterdist, dist[n] - dist[u] + mxdist[u] + (*(--mtsdist1.end())));
            }
            mtsdist1.erase(mtsdist1.lower_bound(dist[par[u]]));
            mxalterdist = max(mxalterdist, dist[n] - dist[u] + (*(--mtsdist1.end())));
            if (mxdist[par[u]]){
                mtsdist1.erase(mtsdist1.lower_bound(dist[par[u]] + mxdist[par[u]]));
            }
            u = par[u];
        }
    }
    while (q--){
        int x; cin >> x;
        cout << min(dist[n], mxalterdist + x) << endl;
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