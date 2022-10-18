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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        vector<vector<bool>> d(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> cnt;
            int mx = 0;
            int sum = 0;
            for (int j = i; j < n; j++) {
                cnt[a[j]]++;
                mx = max(mx, cnt[a[j]]);
                sum++;
                if (mx <= sum - mx && sum % 2 == 0) {
                    d[i][j] = true;
                }
            }
        }
        vector<vector<int>> c(n);
        for (int i = 0; i < n; i++) {
            c[i].emplace_back(-1);
        }
        for (int i = 0; i < n; i++) {
            c[a[i]].emplace_back(i);
        }
        for (int i = 0; i < n; i++) {
            c[i].emplace_back(n);
        }
        int ans = 0;
        for (int x = 0; x < n; x++) {
            vector<int> b;
            swap(b, c[x]);
            int sz = (int) b.size();
            vector<int> dp(sz, (int) 1e9);
            dp[0] = 0;
            for (int i = 0; i < sz; i++) {
                for (int j = i + 1; j < sz; j++) {
                    if (b[i] + 1 < n && b[j] - 1 >= 0 && d[b[i] + 1][b[j] - 1]) {
                        dp[j] = min(dp[j], dp[i] + b[j] - b[i] - 1);
                    } else if (j - i == b[j] - b[i]) {
                        dp[j] = min(dp[j], dp[i]);
                    }
                }
            }
            debug(x, b, dp);
            ans = max(ans, n - dp.back());
        }
        cout << ans << '\n';
    }
    return 0;
}