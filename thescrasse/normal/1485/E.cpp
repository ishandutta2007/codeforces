#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a[200010], a1, b, d, v, dist[200010], dp[200010], s, s1, s2;
vector<ll> adj[200010];
vector<array<ll, 3>> dadj[200010];
bool visited[200010];

void dfs(ll s) {
    for (auto u : adj[s]) {
        if (!visited[u]) {
            visited[u] = true;
            dist[u] = dist[s] + 1;
            dadj[dist[u]].push_back({-1, s, u});
            d = max(d, dist[u]);
            dfs(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i <= n; i++) {
            adj[i].clear(); dadj[i].clear(); visited[i] = false; dist[i] = 0; dp[i] = 0;
        }
        for (i = 2; i <= n; i++) {
            cin >> v;
            adj[v - 1].push_back(i - 1);
            adj[i - 1].push_back(v - 1);
        }

        for (i = 1; i < n; i++) {
            cin >> a[i];
        }

        d = 0;
        visited[0] = true;
        dfs(0);
        dadj[0].push_back({0, -1, 0});

        for (i = 1; i <= d; i++) {
            for (auto& u : dadj[i]) {
                u[0] = a[u[2]];
                // cout << u[0] << ' ' << u[1] << ' ' << u[2] << endl;
            }
            // cout << endl;
            sort(dadj[i].begin(), dadj[i].end());
            s = dadj[i].size();
            s1 = dadj[i][0][0];
            s2 = dadj[i][dadj[i].size() - 1][0];
            // cout << s1 << ' ' << s2 << endl;
            for (auto& u : dadj[i]) {
                a1 = a[u[2]];
                dp[u[2]] = max({dp[u[2]], dp[u[1]] + a1 - s1, dp[u[1]] + s2 - a1});
            }
            k = 0;
            for (j = 0; j < s; j++) {
                if (dp[dadj[i][j][1]] - dadj[i][j][0] > dp[dadj[i][k][1]] - dadj[i][k][0]) {
                    k = j;
                }
                dp[dadj[i][j][2]] = max(dp[dadj[i][j][2]], dadj[i][j][0] - dadj[i][k][0] + dp[dadj[i][k][1]]);
            }
            k = s - 1;
            for (j = s - 1; j >= 0; j--) {
                if (dp[dadj[i][j][1]] + dadj[i][j][0] > dp[dadj[i][k][1]] + dadj[i][k][0]) {
                    k = j;
                }
                dp[dadj[i][j][2]] = max(dp[dadj[i][j][2]], dadj[i][k][0] - dadj[i][j][0] + dp[dadj[i][k][1]]);
            }
        }

        res = 0;
        for (i = 1; i < n; i++) {
            // cout << dp[i] << ' ';
            res = max(res, dp[i]);
        }
        // cout << endl;

        cout << res << endl;
    }

    return 0;
}