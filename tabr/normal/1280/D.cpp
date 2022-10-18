#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            a[i] -= b;
        }
        for (int i = 0; i < n; i++) {
            int w;
            cin >> w;
            a[i] += w;
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        vector<vector<pair<int, long long>>> dp(n);
        function<void(int, int)> dfs = [&](int v, int p) {
            vector<int> q;
            for (int to : g[v]) {
                if (to == p) {
                    continue;
                }
                dfs(to, v);
                q.emplace_back(to);
            }
            if (q.empty()) {
                dp[v].emplace_back(0, a[v]);
                dp[v].emplace_back(a[v] > 0, 0);
                return;
            }
            sort(q.begin(), q.end(), [&](int i, int j) {
                return dp[i].size() < dp[j].size();
            });
            for (int u : q) {
                if (dp[v].empty()) {
                    dp[v] = dp[u];
                    continue;
                }
                vector<pair<int, long long>> new_dp(dp[v].size() + dp[u].size() - 1, {-1, 0});
                for (int i = 0; i < (int)dp[v].size(); i++) {
                    for (int j = 0; j < (int)dp[u].size(); j++) {
                        pair<int, long long> c = dp[v][i];
                        c.first += dp[u][j].first;
                        c.second += dp[u][j].second;
                        new_dp[i + j] = max(new_dp[i + j], c);
                    }
                }
                swap(new_dp, dp[v]);
            }
            if (v == 0) {
                return;
            }
            dp[v].emplace_back(-1, 0);
            for (int i = (int)dp[v].size() - 2; i >= 0; i--) {
                dp[v][i + 1] = max(dp[v][i + 1], {dp[v][i].first + (dp[v][i].second + a[v] > 0), 0});
                dp[v][i].second += a[v];
            }
        };
        dfs(0, -1);
        debug(dp);
        if (dp[0][m - 1].second + a[0] > 0) {
            dp[0][m - 1].first++;
        }
        cout << dp[0][m - 1].first << '\n';
    }
    return 0;
}