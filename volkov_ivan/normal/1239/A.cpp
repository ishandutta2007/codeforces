#include <iostream>
#define int long long

using namespace std;

const int M = 1e9 + 7;
const int MAX_N = 1e5 + 7;
int dp[MAX_N][2][2];

signed main() {
    int n, m;
    cin >> n >> m;
    dp[1][0][1] = dp[1][1][0] = 1;
    for (int i = 2; i <= max(n, m); i++) {
        for (int sec = 0; sec <= 1; sec++) {
            for (int fi = 0; fi <= 1; fi++) {
                if (fi == sec) {
                    dp[i][fi][sec] = dp[i - 1][1 - fi][fi];
                } else {
                    dp[i][fi][sec] = (dp[i - 1][fi][fi] + dp[i - 1][1 - fi][fi]) % M;
                }
            }
        }
    }
    int res = (dp[n][0][1] + dp[n][0][0] + dp[n][1][0] + dp[n][1][1] - 2) % M;
    res = (res + dp[m][0][1] + dp[m][0][0] + dp[m][1][0] + dp[m][1][1] - 2) % M;
    res += 2;
    res %= M;
    if (res < 0) res += M;
    cout << res << endl;
    return 0;
}