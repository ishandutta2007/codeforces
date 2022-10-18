#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC target("popcnt")

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

pii par[N];

int find(int x){
    if (par[x].fi < 0){
        return x;
    }
    find(par[x].fi);
    par[x].se ^= par[par[x].fi].se;
    return (par[x].fi = find(par[x].fi));
}
 
bool merge(int x, int y, int val){
    find(x); find(y);
    val ^= par[x].se;
    val ^= par[y].se;
    x = find(x); y = find(y);
    if (x == y){
        if (val){
            return 0;
        }
        else{
            return 1;
        }
    }
    if (par[x].fi > par[y].fi){
        swap(x, y);
    }
    par[x].fi += par[y].fi;
    par[y].fi = x;
    par[y].se = val;
    return 1;
}

int n, m;
vpii adj[N];

int a[N], b[N];

void dfs(int u, int p){
    Fora(edge, adj[u]){
        if (edge.fi == p){
            continue;
        }
        if (edge.se == -1){
            a[edge.fi] = 0;
            b[edge.fi] = edge.fi;
        }
        else{
            a[edge.fi] = a[u] ^ edge.se;
            b[edge.fi] = b[u];
        }
        dfs(edge.fi, u);
    }
}

void dfs2(int u, int p){
    Fora(edge, adj[u]){
        if (edge.fi == p){
            continue;
        }
        if (edge.se == -1){
            cout << u << ' ' << edge.fi << ' ' << (par[b[u]].se ^ par[b[edge.fi]].se ^ (__builtin_popcount(a[u]) & 1)) << endl;
        }
        else{
            cout << u << ' ' << edge.fi << ' ' << edge.se << endl;
        }
        dfs2(edge.fi, u);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> m;
    ForE(i, 1, n){
        adj[i].clear();
    }
    For(i, 1, n){
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    ForE(i, 1, n){
        a[i] = 0; b[i] = 1;
        par[i] = make_pair(-1, 0);
    }
    dfs(1, 0);

    bool ans = 1;
    ForE(i, 1, m){
        int u, v, w; cin >> u >> v >> w;
        w ^= (__builtin_popcount(a[u] ^ a[v]) & 1); u = b[u]; v = b[v];
        ans &= merge(u, v, w);
    }
    if (ans == 0){
        cout << "NO" << endl;
        continue;
    }
    cout << "YES" << endl;
    ForE(i, 1, n){
        find(i);
    }
    dfs2(1, 0);
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