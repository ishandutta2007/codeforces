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
        long long t;
        int x, y;
        cin >> t >> x >> y;
        if (t < x + y) {
            cout << "NO" << '\n';
            continue;
        }
        t -= x + y;
        vector<vector<long long>> dp(121, vector<long long>(121));
        dp[0][0] = t;
        for (int i = 0; i < 120; i++) {
            for (int j = 0; j < 120; j++) {
                dp[i][j + 1] += (dp[i][j] + 1) / 2;
                dp[i + 1][j] += dp[i][j] / 2;
            }
        }
        string ans = "NO";
        int i = 0, j = 0;
        while (max(i, j) < 120) {
            if (x == i && y == j) {
                ans = "YES";
            }
            if (dp[i][j] % 2 == 0) {
                j++;
            } else {
                i++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}