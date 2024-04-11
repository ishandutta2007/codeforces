#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        int k;
        cin >> k;
        vector<vector<int>> g(2 * k);
        vector<pair<pair<int, int>, ll>> e;
        for (int i = 0; i < 2 * k - 1; i++) {
            int a, b, t;
            cin >> a >> b >> t;
            a--, b--;
            g[a].emplace_back(e.size());
            g[b].emplace_back(e.size());
            e.emplace_back(pair<int, int>(a, b), t);
        }
        vector<ll> dp(2 * k);
        function<int(int, int)> dfs = [&](int v, int eg) {
            if (dp[eg] != 0) {
                return dp[eg];
            }
            dp[eg] = 1;
            for (int i : g[v]) {
                if (i == eg) {
                    continue;
                }
                int to = v ^ e[i].first.first ^ e[i].first.second;
                dp[eg] += dfs(to, i);
            }
            return dp[eg];
        };
        dfs(0, 2 * k - 1);
        ll G = 0, B = 0;
        debug(dp);
        for (int i = 0; i < 2 * k - 1; i++) {
            dp[i] = min(dp[i], 2 * k - dp[i]);
            G += (dp[i] % 2) * e[i].second;
            B += dp[i] * e[i].second;
        }
        cout << G << " " << B << endl;
    }
    return 0;
}