#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")

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

const int N = 5e5 + 5;

__attribute__((always_inline)) void smax(int& a, int b){
    a = a > b ? a : b;
}

int n;
vector <pair <int, char>> adj[N];

int h[N], sz[N];
int ctrtin; pii tin[N]; int invtin[N];
int a[N];
int mpp[1 << 22];
int ans[N];

void dfs1(int u){
    sz[u] = 1;
    tin[u].fi = ++ctrtin;
    invtin[ctrtin] = u;
    Fora(&edge, adj[u]){
        int v = edge.fi;
        h[v] = h[u] + 1;    
        a[v] = a[u] ^ (1 << (edge.se - 'a'));
        dfs1(v);
        sz[u] += sz[v];
    }
    tin[u].se = ctrtin;
}

void dfs2(int u, bool keep){
    int heavy = 0;
    Fora(&edge, adj[u]){
        int v = edge.fi;
        if (sz[v] > sz[heavy]){
            heavy = v;
        }
    }
    Fora(&edge, adj[u]){
        int v = edge.fi;
        if (v != heavy){
            dfs2(v, 0);
            smax(ans[u], ans[v]);
        }
    }
    if (heavy){
        dfs2(heavy, 1);
        smax(ans[u], ans[heavy]);
    }
    ans[u] += 2 * h[u];
    Fora(&edge, adj[u]){
        int v = edge.fi;
        if (v != heavy){
            ForE(i, tin[v].fi, tin[v].se){
                int tv = invtin[i];
                if (mpp[a[tv]]){
                    smax(ans[u], mpp[a[tv]] + h[tv]);
                }
                For(j, 0, 22){
                    if (mpp[a[tv] ^ (1 << j)]){
                        smax(ans[u], mpp[a[tv] ^ (1 << j)] + h[tv]);
                    }
                }
            }
            ForE(i, tin[v].fi, tin[v].se){
                int tv = invtin[i];
                smax(mpp[a[tv]], h[tv]);
            }
        }
    }
    int tv = u;
    if (mpp[a[tv]]){
        smax(ans[u], mpp[a[tv]] + h[tv]);
    }
    For(j, 0, 22){
        if (mpp[a[tv] ^ (1 << j)]){
            smax(ans[u], mpp[a[tv] ^ (1 << j)] + h[tv]);
        }
    }
    smax(mpp[a[tv]], h[tv]);
    if (!keep){
        ForE(i, tin[u].fi, tin[u].se){
            mpp[a[invtin[i]]] = 0;
        }
    }
    ans[u] -= 2 * h[u];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 2, n){
        int j; char c; cin >> j >> c;
        adj[j].emplace_back(i, c);
    }
    dfs1(1);
    dfs2(1, 1);
    ForE(i, 1, n){
        cout << ans[i] << ' ';
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