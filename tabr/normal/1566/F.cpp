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
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<vector<pair<long long, long long>>> b(n + 1), c(n + 1);
        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            auto it = lower_bound(a.begin(), a.end(), l);
            if (it == a.end() || *it > r) {
                b[it - a.begin()].emplace_back(l, r);
            }
        }
        if (!b[0].empty()) {
            long long z = b[0][0].second;
            for (auto p : b[0]) {
                z = min(z, p.second);
            }
            c[0].emplace_back(z, z);
        } else {
            c[0].emplace_back(a[0], a[0]);
        }
        if (!b[n].empty()) {
            long long z = b[n][0].first;
            for (auto p : b[n]) {
                z = max(z, p.first);
            }
            c[n].emplace_back(z, z);
        } else {
            c[n].emplace_back(a[n - 1], a[n - 1]);
        }
        for (int i = 1; i < n; i++) {
            if (b[i].empty()) {
                c[i].emplace_back(a[i - 1], a[i]);
                continue;
            }
            sort(b[i].begin(), b[i].end());
            for (int j = (int) b[i].size() - 1; j > 0; j--) {
                b[i][j - 1].second = min(b[i][j].second, b[i][j - 1].second);
            }
            c[i].emplace_back(a[i - 1], b[i][0].second);
            for (int j = 1; j < (int) b[i].size(); j++) {
                if (b[i][j].second > c[i].back().second) {
                    c[i].emplace_back(b[i][j - 1].first, b[i][j].second);
                }
            }
            c[i].emplace_back(b[i].back().first, a[i]);
        }
        debug(a);
        debug(b);
        debug(c);
        long long inf = (long long) 1e18;
        vector<vector<long long>> dp(n + 2, vector<long long>(2, inf));
        dp[0][0] = dp[0][1] = 0;
        a.insert(a.begin(), c[0][0].first);
        a.emplace_back(c[n][0].second);
        for (int i = 0; i <= n; i++) {
            long long x = a[i];
            long long y = a[i + 1];
            for (auto [l, r] : c[i]) {
                debug(x, y, l, r);
                long long dl = abs(l - x);
                long long dr = abs(r - y);
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + dl * (2 - j) + dr * (k + 1));
                    }
                }
            }
        }
        cout << min(dp[n + 1][0], dp[n + 1][1]) << '\n';
        debug(dp);
    }
    return 0;
}