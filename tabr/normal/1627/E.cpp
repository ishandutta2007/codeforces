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
        int n, m, k;
        cin >> n >> m >> k;
        vector<long long> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        vector<vector<int>> a(k, vector<int>(5));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> a[i][j];
                if (j != 4) {
                    a[i][j]--;
                }
            }
        }
        sort(a.begin(), a.end());
        vector<unordered_map<int, long long>> dp(n);
        vector<vector<int>> c(n);
        const long long inf = (long long) 1e18;
        for (int i = 0; i < k; i++) {
            auto b = a[i];
            c[b[0]].emplace_back(i);
            dp[b[0]][b[1]] = inf;
            dp[b[2]][b[3]] = inf;
        }
        dp[0][0] = 0;
        dp[n - 1][m - 1] = inf;
        for (int i = 0; i < n; i++) {
            if (dp[i].empty()) {
                continue;
            }
            vector<int> y;
            for (auto p : dp[i]) {
                y.emplace_back(p.first);
            }
            sort(y.begin(), y.end());
            int sz = (int) y.size();
            long long z = inf;
            for (int j = 0; j < sz; j++) {
                z += x[i] * y[j];
                z = dp[i][y[j]] = min(z, dp[i][y[j]]);
                z -= x[i] * y[j];
            }
            z = inf * 2;
            for (int j = sz - 1; j >= 0; j--) {
                z -= x[i] * y[j];
                z = dp[i][y[j]] = min(z, dp[i][y[j]]);
                z += x[i] * y[j];
            }
            for (int j : c[i]) {
                auto b = a[j];
                if (dp[b[0]][b[1]] != inf) {
                    dp[b[2]][b[3]] = min(dp[b[2]][b[3]], dp[b[0]][b[1]] - b[4]);
                }
            }
        }
        if (dp[n - 1][m - 1] == inf) {
            cout << "NO ESCAPE" << '\n';
        } else {
            cout << dp[n - 1][m - 1] << '\n';
        }
    }
    return 0;
}