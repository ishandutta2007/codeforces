#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    vector<int> lenDp(n + 1);
    iota(lenDp.begin(), lenDp.end(), 0);
    for (int j = 1; j <= n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (j == 1) {
                dp[i][j] = a[i];
            } else if (i + j <= n) {
                for (int k = 1; k < j; ++k) {
                    if (dp[i][k] != -1 && dp[i][k] == dp[i + k][j - k]) {
                        dp[i][j] = dp[i][k] + 1;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] != -1) {
                lenDp[i + j] = min(lenDp[i + j], lenDp[i] + 1);
            }
        }
    }
    cout << lenDp[n] << '\n';
}