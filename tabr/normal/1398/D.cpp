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
    vector<int> c(3);
    for (int i = 0; i < 3; i++) {
        cin >> c[i];
    }
    vector<vector<ll>> a(3);
    for (int i = 0; i < 3; i++) {
        a[i].resize(c[i]);
        for (int j = 0; j < c[i]; j++) {
            cin >> a[i][j];
        }
        sort(a[i].rbegin(), a[i].rend());
    }
    vector<vector<vector<ll>>> dp(210, vector<vector<ll>>(210, vector<ll>(210)));
    ll ans = 0;
    for (int i = 0; i <= c[0]; i++) {
        for (int j = 0; j <= c[1]; j++) {
            for (int k = 0; k <= c[2]; k++) {
                if ((i + j + k) % 2 == 1) {
                    continue;
                }
                if (i && j) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[0][i - 1] * a[1][j - 1]);
                }
                if (j && k) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + a[2][k - 1] * a[1][j - 1]);
                }
                if (k && i) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[2][k - 1] * a[0][i - 1]);
                }
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}