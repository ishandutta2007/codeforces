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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<tuple<int, int, int>>> b(n);
        for (int i = 0; i < m; i++) {
            int e, t, p;
            cin >> e >> t >> p;
            e--;
            b[e].emplace_back(t, p, i);
        }
        vector<int> ans;
        const int inf = (int) 1.01e9;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            vector<vector<int>> dp(b[i].size() + 1, vector<int>(200, inf));
            dp[0][0] = 0;
            for (int j = 0; j < (int) b[i].size(); j++) {
                dp[j + 1] = dp[j];
                auto [t, p, id] = b[i][j];
                for (int k = 199; k >= 0; k--) {
                    if (dp[j][k] == inf || k + p >= 200) {
                        continue;
                    }
                    dp[j + 1][k + p] = min(dp[j + 1][k + p], dp[j][k] + t);
                }
            }
            int c = *min_element(dp.back().begin() + 100, dp.back().end());
            sum += c;
            if (c == inf || sum > a[i]) {
                ans = vector<int>(1, -1);
                break;
            }
            int now = (int) (min_element(dp.back().begin() + 100, dp.back().end()) - dp.back().begin());
            for (int j = (int) b[i].size() - 1; j >= 0; j--) {
                auto [t, p, id] = b[i][j];
                if (now - p >= 0 && dp[j][now - p] + t == dp[j + 1][now]) {
                    now -= p;
                    ans.emplace_back(id + 1);
                }
            }
            assert(now == 0);
        }
        if (ans[0] == -1) {
            cout << -1 << '\n';
        } else {
            cout << ans.size() << '\n';
            for (int i : ans) {
                cout << i << " \n"[i == ans.back()];
            }
        }
    }
    return 0;
}