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

const int N = 1e5 + 5;

int n;
int a[N][2];
vi adj[N];
ll dp[N][2];

void dfs(int u, int p){
    dp[u][0] = dp[u][1] = 0;
    Fora(&v, adj[u]){
        if (v == p){
            continue;
        }
        dfs(v, u);
        dp[u][0] += max(dp[v][0] + abs(a[u][0] - a[v][0]), dp[v][1] + abs(a[u][0] - a[v][1]));
        dp[u][1] += max(dp[v][0] + abs(a[u][1] - a[v][0]), dp[v][1] + abs(a[u][1] - a[v][1]));
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i][0] >> a[i][1];
    }
    ForE(i, 1, n){
        adj[i].clear();
    }
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 1);
    cout << max(dp[1][0], dp[1][1]) << endl;
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