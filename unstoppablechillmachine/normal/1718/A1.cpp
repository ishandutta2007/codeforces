#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

const int N = 5010;
const int M = 1 << 13;
int dp[N][M];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        a[n] = 0;
        //vector<vector<int>> dp(n + 1, vector<int>(1 << 13, 1e9));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < (1 << 13); j++) {
                dp[i][j] = 1e9;
            }
        }
        dp[0][a[0]] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << 13); j++) {
                 if (!j) {
                     dp[i + 1][a[i + 1]] = min(dp[i + 1][a[i + 1]], dp[i][j]);
                 } else {
                     dp[i + 1][a[i + 1] ^ j] = min(dp[i + 1][a[i + 1] ^ j], dp[i][j] + 1);
                     dp[i + 1][a[i + 1]] = min(dp[i + 1][a[i + 1]], dp[i][j] + 1);
                 }
            }
        }
        int ans = 1e9;
        for (int j = 0; j < (1 << 13); j++) {
            ans = min(ans, dp[n][j]);
        }
        cout << ans << '\n';
    }
    return 0;
}