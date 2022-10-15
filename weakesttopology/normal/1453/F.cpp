#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 3000, inf = 1e6;
int dp[nmax][nmax + 1];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> r(n);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            r[i] = i + a;
        }
        r[n - 1] = n, dp[n - 1][n] = 0;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= n; ++j) dp[i][j] = inf;
            vector<int> cnt(n + 1);
            int cross = 0;
            for (int j = i + 1; j <= r[i]; ++j) {
                if (r[j] > r[i]) {
                    dp[i][j] = dp[j][r[i] + 1] + cross;
                }
                ++cnt[r[j]];
                cross += 1 - cnt[j];
            }
            for (int j = r[i]; j >= i + 1; --j) {
                dp[i][j] = min(dp[i][j], dp[i][j + 1]);
            }
        }
        cout << dp[0][1] << endl;
    }
    exit(0);
}