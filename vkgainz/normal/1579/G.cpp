#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int dp[10001][2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        memset(dp[0], 0, sizeof(dp[0]));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 2000; j++) {
                dp[i][j] = 100000000;
                if (j >= a[i - 1]) {
                    dp[i][j] = min(dp[i][j], max(dp[i  - 1][j - a[i - 1]]
                            - a[i - 1], 0));
                }
                if (j + a[i - 1] <= 2000) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + a[i - 1]]
                            + a[i - 1]);
                }
            }
        }
        int ans = 10000000;
        for (int i = 0; i <= 2000; i++) {
            ans = min(ans, i + dp[n][i]);
        }
        cout << ans << "\n";
    }
}