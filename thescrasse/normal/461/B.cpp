// 461B
// rimozione di archi in modo tale che tutte le componenti abbiano un solo nodo nero

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, mod, c[100010], dp[100010][2], dpold[2];
bool visited[100010];
vector<ll> adj[100010];

void dfs(int s) {
    dp[s][0] = 1 - c[s];
    dp[s][1] = c[s];
    for (auto u : adj[s]) {
        if (!visited[u]) {
            visited[u] = true;
            dfs(u);
            dpold[0] = dp[s][0]; dpold[1] = dp[s][1];
            dp[s][0] = 0; dp[s][1] = 0;
            dp[s][0] += (dpold[0] * (dp[u][0] + dp[u][1])) % mod;
            dp[s][1] += (dpold[0] * dp[u][1] + dpold[1] * (dp[u][0] + dp[u][1])) % mod;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    mod = 1000000007;
    cin >> n;
    for (i = 0; i < n - 1; i++) {
        cin >> a;
        adj[a].push_back(i + 1);
        adj[i + 1].push_back(a);
    }
    for (i = 0; i < n; i++) {
        cin >> c[i];
    }

    visited[0] = true;
    dfs(0);
    cout << dp[0][1];

    return 0;
}