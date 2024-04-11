#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<int> sum(n + 1);
    for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + a[i];
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 1e9));
    dp[0][m] = 0;
    for(int i = 0; i < n; ++i) {
        vector<vector<int>> ndp(m + 1, vector<int>(m + 1, 1e9));
        for(int j = 0; j <= m; ++j) {
            for(int k = 0; k <= m; ++k) {
                if(dp[j][k] == 1e9) continue;
                for(int x = 0; x <= k && j + x <= m; ++x) {
                    ndp[j + x][x] = min(ndp[j + x][x], dp[j][k] + abs(sum[i + 1] - (j + x)));
                }
            }
        }
        dp = ndp;
    }
    int ans = 1e9;
    for(int k = 0; k <= m; ++k) {
        ans = min(ans, dp[m][k]);
    }
    cout << ans << '\n';
}