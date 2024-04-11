// 1332F
// Independent Set

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dp[maxn][4];
bool vis[maxn];
vector<ll> adj[maxn];

void fx(ll s) {
    ll i;
    for (i = 1; i <= 3; i++) {
        dp[s][i] %= mod; dp[s][i] += mod; dp[s][i] %= mod;
    }
}

void dfs(ll s) {
    dp[s][1] = 1; dp[s][2] = 1; dp[s][3] = 1;
    for (auto u : adj[s]) {
        if (vis[u]) continue;
        vis[u] = true; dfs(u);

        dp[s][1] *= (dp[u][1] + dp[u][2] + dp[u][3]);
        dp[s][2] *= (3 * dp[u][1] + 2 * dp[u][2] + 2 * dp[u][3]);
        dp[s][3] *= (2 * dp[u][1] + 2 * dp[u][2] + dp[u][3]);
        fx(s);
    }

    dp[s][2] -= dp[s][1]; dp[s][3] -= dp[s][1]; fx(s);
}

void init(ll s) {
    vis[s] = true; dfs(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    init(1);

    /* for (i = 1; i <= n; i++) {
        for (j = 1; j <= 5; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << nl;
    } */

    res = (dp[1][1] + dp[1][2] + dp[1][3] + mod - 1) % mod;

    cout << res << nl;

    return 0;
}