// 486D
// percorsi in un tree con differenza max valore nodi <= d

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a[2010], b, d, u, v, dp[2010], mod;
bool visited[2010];
vector<ll> adj[2010];

void dfs(ll st, ll s, ll k) {
    ll i, j;
    dp[s] = 1;
    for (auto u : adj[s]) {
        if (a[u] == k && u < st) {
            continue;
        }
        if (!visited[u] && a[u] >= k && a[u] <= k + d) {
            visited[u] = true;
            dfs(st, u, k);
            dp[s] = (dp[s] * (dp[u] + 1)) % mod;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    mod = 1000000007;
    cin >> d >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    res = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            visited[j] = false;
        }
        visited[i] = true;
        dfs(i, i, a[i]);
        res += dp[i]; res %= mod;
    }

    cout << res;

    return 0;
}