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

const int N = 5e3 + 5;
const ll infll = (ld)1e18 + 7;

int n, k;
int c[N], d[N], par[N];
vi adj[N];

int sz[N];
ll dp1[N][N], dp2[N][N];

void dfs_sz(int u){
    sz[u] = 1;
    Fora(&v, adj[u]){
        dfs_sz(v);
        sz[u] += sz[v];
    }
}

vi vsubtree[N];

void dfs_dp2(int u){
    vsubtree[u].emplace_back(c[u]);
    Fora(&v, adj[u]){
        dfs_dp2(v);
        vsubtree[u].insert(vsubtree[u].end(), bend(vsubtree[v]));
    }
    sort(bend(vsubtree[u]));
    ForE(i, 1, sz[u]){
        dp2[u][i] = dp2[u][i - 1] + vsubtree[u][i - 1];
    }
}

void dfs_dp1(int u){
    int sum = 1;
    dp1[u][0] = 0;
    dp1[u][1] = c[u] - d[u];
    Fora(&v, adj[u]){
        dfs_dp1(v);
        FordE(i, sum + sz[v], 1){
            ForE(j, max(1, i - sz[v]), min(sum, i - 1)){
                dp1[u][i] = min(dp1[u][i], dp1[u][j] + dp1[v][i - j]);
            }
        }
        sum += sz[v];
    }
    ForE(i, 1, sz[u]){
        dp1[u][i] = min(dp1[u][i], dp2[u][i]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> c[i] >> d[i];
        if (i != 1){
            cin >> par[i];
            adj[par[i]].emplace_back(i);
        }
    }
    dfs_sz(1);
    dfs_dp2(1);
    memset(dp1, 0x3f, sizeof(dp1));
    dfs_dp1(1);
    int ans = 0;
    ForE(i, 1, n){
        if (dp1[1][i] <= k){
            ans = i;
        }
    }
    cout << ans << endl;
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