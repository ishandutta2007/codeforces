#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> E(N);
        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            E[u].push_back(v), E[v].push_back(u);
        }
        vector<array<long long, 2>> dp(N, {0, -inf});
        auto mx = [&](int u) {
            return max(dp[u][0], dp[u][1]);
        };
        auto dfs = [&](auto &self, int u, int p) -> void {
            long long sum = 0;
            bool leaf = true;
            for (auto v : E[u]) {
                if (v == p) continue;
                self(self, v, u);
                dp[u][0] += dp[v][1];
                dp[u][0] = max(dp[u][0], -inf);
                sum += mx(v);
                leaf = false;
            }
            dp[u][0] -= 1;
            for (auto v : E[u]) {
                if (v == p) continue;
                dp[u][1] = max(dp[u][1], sum - mx(v) + dp[v][0] + 1);
            }
        };
        dfs(dfs, 0, -1);
        long long cost = -max(dp[0][0], dp[0][1] - 1);
        cout << cost << '\n';
    }
    exit(0);
}