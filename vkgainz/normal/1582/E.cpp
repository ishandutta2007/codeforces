#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<long long> p(n + 1);
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + a[i - 1];
        }
        const int SQRT = sqrt(2 * n) + 1;
        vector<vector<long long>> dp(n + 1, vector<long long>(SQRT + 1, -1e9));
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= SQRT; j++) {
                if (i < n) {
                    dp[i][j] = dp[i + 1][j];
                }
                if (j * (j + 1) / 2 > n - i + 1) {
                    continue;
                }
                long long curr = p[i + j - 1] - p[i - 1];
                if (j == 1) {
                    dp[i][j] = max(dp[i][j], curr);

                } else {
                    if (dp[i + j][j - 1] > curr) {
                        dp[i][j] = max(dp[i][j], curr);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= SQRT; i++) {
            if (dp[1][i] != -1e9) {
                ans = i;
            }
        }
        cout << ans << "\n";
    }
}