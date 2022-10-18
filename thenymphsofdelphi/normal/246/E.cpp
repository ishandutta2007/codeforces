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

int n, q;
string s[N]; int a[N];
int par[N];
vpii queries[N];

vi adj[N];
int ans[N];

int h[N], sz[N];
int ctrtour, tour[N], tin[N], tout[N];

void dfs1(int u){
    sz[u] = 1;
    tour[++ctrtour] = u;
    tin[u] = ctrtour;
    Fora(&v, adj[u]){
        h[v] = h[u] + 1;
        dfs1(v);
        sz[u] += sz[v];
    }
    tout[u] = ctrtour;
}

set <int> stt[N];

void dfs2(int u, bool keep){
    int heavy = -1;
    Fora(&v, adj[u]){
        if (heavy == -1 or sz[v] > sz[heavy]){
            heavy = v;
        }
    }
    Fora(&v, adj[u]){
        if (v != heavy){
            dfs2(v, 0);
        }
    }
    if (heavy != -1){
        dfs2(heavy, 1);
    }
    Fora(&v, adj[u]){
        if (v != heavy){
            ForE(i, tin[v], tout[v]){
                stt[h[tour[i]]].insert(a[tour[i]]);
            }
        }
    }
    stt[h[u]].insert(a[u]);
    Fora(&query, queries[u]){
        ans[query.se] = isz(stt[h[u] + query.fi]);
    }
    if (!keep){
        ForE(i, tin[u], tout[u]){
            stt[h[tour[i]]].clear();
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
        cin >> s[i] >> par[i];
        adj[par[i]].emplace_back(i);
    }
    {
        int ctrmpp = 0; map <string, int> mpp;
        ForE(i, 1, n){
            mpp[s[i]] = 1;
        }
        Fora(&elem, mpp){
            elem.se = ++ctrmpp;
        }
        ForE(i, 1, n){
            a[i] = mpp[s[i]];
        }
    }
    cin >> q;
    ForE(i, 1, q){
        int u, k; cin >> u >> k;
        queries[u].emplace_back(k, i);
    }

    dfs1(0);
    dfs2(0, 1);
    ForE(i, 1, q){
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