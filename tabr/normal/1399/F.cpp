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
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        vector<int> b(2 * n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            b[i] = a[i].first;
            b[i + n] = a[i].second;
        }
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        int m = b.size();
        vector<vector<int>> x(m);
        for (int i = 0; i < n; i++) {
            a[i].first = lower_bound(b.begin(), b.end(), a[i].first) - b.begin();
            a[i].second = lower_bound(b.begin(), b.end(), a[i].second) - b.begin();
            x[a[i].first].emplace_back(a[i].second);
        }
        vector<vector<int>> dp(m, vector<int>(m));
        for (int i = 0; i < n; i++) {
            dp[a[i].first][a[i].second]++;
        }
        for (int p = 1; p < m; p++) {
            for (int i = 0; i + p < m; i++) {
                int t = 0;
                for (int j : x[i]) {
                    if (j + 1 <= i + p) {
                        t = max(t, dp[i][j] + dp[j + 1][i + p]);
                    }
                }
                t = max({t, dp[i + 1][i + p], dp[i][i + p - 1]});
                dp[i][i + p] += t;
            }
        }
        cout << dp[0][m - 1] << '\n';
    }
    return 0;
}