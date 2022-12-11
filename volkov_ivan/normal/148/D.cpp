#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1007;
long double dp[N][N][2];

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    int w, b;
    cin >> w >> b;
    dp[0][0][0] = 0;
    dp[0][0][1] = 1;
    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= b; j++) {
            if (i == 0 && j == 0) continue;
            if (i == 0) dp[i][j][0] = 0;
            else {
                dp[i][j][0] = 1.0 * i / (i + j) + 1.0 * j / (i + j) * (1 - dp[i][j - 1][1]);
            }
            if (i == 0) dp[i][j][1] = 1;
            else {
                dp[i][j][1] = 0;
                dp[i][j][1] += 1.0 * i / (i + j);
                if (i + j != 1) {
                    dp[i][j][1] += 1.0 * j / (i + j) * (1.0 * i / (i + j - 1) * (1 - dp[i - 1][j - 1][0]));
                    if (j > 1) dp[i][j][1] += 1.0 * j / (i + j) * (1.0 * (j - 1) / (i + j - 1) * (1 - dp[i][j - 2][0]));
                }
            }
        }
    }
    cout << fixed << dp[w][b][0] << endl;
}