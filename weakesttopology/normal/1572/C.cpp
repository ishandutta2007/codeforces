#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        vector<vector<int>> pos(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
            --a[i];
            pos[a[i]].push_back(i);
        }
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, numeric_limits<int>::max()));
        for (int i = 0; i <= N; ++i) {
            dp[i][i] = 0;
        }
        for (int len = 1; len <= N; ++len) {
            for (int l = 0; l + len <= N; ++l) {
                int r = l + len;
                dp[l][r] = dp[l + 1][r] + (len > 1);
                for (auto i : pos[a[l]]) {
                    if (l < i && i < r) {
                        dp[l][r] = min(dp[l][r], dp[l][i] + dp[i][r]);
                    }
                }
            }
        }
        cout << dp[0][N] << '\n';
    }
    exit(0);
}