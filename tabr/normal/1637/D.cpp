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
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int s = accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(s + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = s - a[i]; j >= 0; j--) {
                if (dp[i][j]) {
                    dp[i + 1][j + a[i]] = 1;
                }
            }
            for (int j = s - b[i]; j >= 0; j--) {
                if (dp[i][j]) {
                    dp[i + 1][j + b[i]] = 1;
                }
            }
        }
        int now = -10;
        for (int i = 0; i <= s; i++) {
            if (dp[n][i]) {
                if (abs(s / 2 - now) > abs(s / 2 - i)) {
                    now = i;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (now - a[i] >= 0 && dp[i][now - a[i]]) {
                now -= a[i];
            } else if (now - b[i] >= 0 && dp[i][now - b[i]]) {
                now -= b[i];
                swap(a[i], b[i]);
            } else {
                assert(false);
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += (a[i] + a[j]) * (a[i] + a[j]);
                ans += (b[i] + b[j]) * (b[i] + b[j]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}