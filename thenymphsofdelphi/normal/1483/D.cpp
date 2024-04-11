#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long

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

const int N = 6e2 + 5, inf = (ld)1e9 + 7;
const ll infll = (ld)1e18 + 7;

int n, m;
ll adj[N][N];
vpii queries[N];
ll dist1[N], dist2[N];
bool ck[N], ans[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ForE(i, 1, n){
        ForE(j, 1, n){
            if (i == j){
                adj[i][j] = 0;
            }
            else{
                adj[i][j] = infll;
            }
        }
    }
    ForE(i, 1, m){
        int u, v, w; cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = w;
    }
    int q; cin >> q; while (q--){
        int u, v, l; cin >> u >> v >> l;
        if (u > v){
            swap(u, v);
        }
        queries[u].emplace_back(v, l);
    }
    ForE(i, 1, n){
        if (!isz(queries[i])){
            continue;
        }
        ForE(j, 1, n){
            adj[j][n + 1] = adj[n + 1][j] = infll;
        }
        int mxl = 0;
        Fora(&query, queries[i]){
            int v = query.fi, l = query.se; mxl = max(mxl, l);
        }
        mxl *= 2;
        Fora(&query, queries[i]){
            int v = query.fi, l = query.se;
            adj[v][n + 1] = adj[n + 1][v] = mxl - l;
        }
        memset(dist1, 0x3f, sizeof(dist1));
        memset(ck, 0, sizeof(ck));
        dist1[i] = 0;
        ForE(turn, 1, n + 1){
            int u = N - 1;
            ForE(j, 1, n + 1){
                if (!ck[j] && dist1[j] < dist1[u]){
                    u = j;
                }
            }
            if (u == N - 1){
                break;
            }
            ck[u] = 1;
            ForE(j, 1, n + 1){
                dist1[j] = min(dist1[j], dist1[u] + adj[u][j]);
            }
        }
        memset(dist2, 0x3f, sizeof(dist2));
        memset(ck, 0, sizeof(ck));
        dist2[n + 1] = 0;
        ForE(turn, 1, n + 1){
            int u = N - 1;
            ForE(j, 1, n + 1){
                if (!ck[j] && dist2[j] < dist2[u]){
                    u = j;
                }
            }
            if (u == N - 1){
                break;
            }
            ck[u] = 1;
            ForE(j, 1, n + 1){
                dist2[j] = min(dist2[j], dist2[u] + adj[u][j]);
            }
        }
        ForE(j, 1, n){
            ForE(k, 1, n){
                if (j == k){
                    continue;
                }
                if (dist1[j] + dist2[k] + adj[j][k] <= mxl){
                    ans[j][k] = ans[k][j] = 1;
                }
            }
        }
    }
    int tans = 0;
    ForE(i, 1, n){
        ForE(j, 1, n){
            if (ans[i][j]){
                tans++;
            }
        }
    }
    cout << tans / 2 << endl;
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