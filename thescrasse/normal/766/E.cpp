// 766E
// Mahmoud and a xor trip

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, flag, a[100010], b, w[100010], dp[100010][2], cn, parent[100010], u, v, p[100010][2];
bool visited[100010];
vector<ll> adj[100010];

void dfs(ll s) {
    ll i, sm[2];
    dp[s][0] = 0; dp[s][1] = 0;
    p[s][0] = 0; p[s][1] = 0;
    dp[s][w[s]]++;
    sm[0] = 0; sm[1] = 0;
    for (auto u : adj[s]) {
        if (!visited[u]) {
            visited[u] = true;
            parent[u] = s;
            dfs(u);
            for (i = 0; i < 2; i++) {
                dp[s][i ^ w[s]] += dp[u][i];
            }

            p[s][w[s]] += sm[0] * dp[u][0] + sm[1] * dp[u][1];
            p[s][1 ^ w[s]] += sm[0] * dp[u][1] + sm[1] * dp[u][0];

            for (i = 0; i < 2; i++) {
                sm[i] += dp[u][i];
            }
        }
    }
    p[s][0] += dp[s][0]; p[s][1] += dp[s][1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    res = 0;
    for (i = 0; i < 23; i++) {
        for (j = 1; j <= n; j++) {
            w[j] = 0; visited[j] = false;
            if (((a[j] >> i) & 1) == 1) w[j] = 1;
        }
        visited[1] = true; dfs(1);

        for (j = 1; j <= n; j++) {
            // cout << j << ' ' << p[j][0] << ' ' << p[j][1] << endl;
            res += (ll)(1 << i) * p[j][1];
        }
    }

    cout << res;

    return 0;
}