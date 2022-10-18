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
    int m = 2010;
    vector dp(m + 1, vector(m + 1, vector<int>(2)));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 2; k++) {
                if (!(i + j + k)) {
                    continue;
                }
                dp[i][j][k] = (int)-1e9;
                if (i) {
                    dp[i][j][k] = max(dp[i][j][k], -1 - dp[i - 1][j + 1][k]);
                }
                if (j) {
                    dp[i][j][k] = max(dp[i][j][k], -1 - dp[i][j - 1][k]);
                }
                if (k) {
                    dp[i][j][k] = max(dp[i][j][k], -1 - dp[i][j][k - 1]);
                }
                if (j) {
                    dp[i][j][k] = max(dp[i][j][k], -dp[i][j][k]);
                }
            }
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a = 0, b = 0, c = 0;
        for (int i = 0; i <= n - 1 - i; i++) {
            if (s[i] == '0' && s[n - 1 - i] == '0') {
                if (i < n - 1 - i) {
                    a++;
                } else {
                    c++;
                }
            } else if (s[i] != '1' || s[n - 1 - i] != '1') {
                b++;
            }
        }
        if (dp[a][b][c] > 0) {
            cout << "ALICE" << '\n';
        } else if (dp[a][b][c] < 0) {
            cout << "BOB" << '\n';
        } else {
            cout << "DRAW" << '\n';
        }
    }
    return 0;
}