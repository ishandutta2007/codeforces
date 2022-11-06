#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, inf = 1e9 + 1;
int dp[4][maxn][maxn]; // 0: right max, 1: right min, 2: left max, 3: left min

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s; s = '.' + s;
    int n; cin >> n;
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) {
        dp[0][i][j] = dp[2][i][j] = -inf;
        dp[1][i][j] = dp[3][i][j] = inf;
    }
    dp[0][0][0] = dp[1][0][0] = dp[2][0][0] = dp[3][0][0] = 0;
    for (int k = 0; k <= n; ++k) {
        for (int i = 1; i < s.length(); ++i) {
            dp[1][k][i] = dp[3][k][i] = inf;
            dp[0][k][i] = dp[2][k][i] = -inf;
            for (int j = 0; j <= k; ++j) {
                char cmd = (s[i] == 'F' ? j % 2 ? 'T' : 'F' : j % 2 ? 'F' : 'T');
                if (cmd == 'F') {
                    dp[0][k][i] = max(dp[0][k][i], dp[0][k - j][i - 1] + 1);
                    dp[1][k][i] = min(dp[1][k][i], dp[1][k - j][i - 1] + 1);
                    dp[2][k][i] = max(dp[2][k][i], dp[2][k - j][i - 1] - 1);
                    dp[3][k][i] = min(dp[3][k][i], dp[3][k - j][i - 1] - 1);
                } else {
                    dp[0][k][i] = max(dp[0][k][i], dp[2][k - j][i - 1]);
                    dp[1][k][i] = min(dp[1][k][i], dp[3][k - j][i - 1]);
                    dp[2][k][i] = max(dp[2][k][i], dp[0][k - j][i - 1]);
                    dp[3][k][i] = min(dp[3][k][i], dp[1][k - j][i - 1]);
                }
            }
        }
    }
    cout << max(max(dp[0][n][s.length() - 1], dp[2][n][s.length() - 1]), -min(dp[1][n][s.length() - 1], dp[3][n][s.length() - 1])) << endl;
    return 0;
}