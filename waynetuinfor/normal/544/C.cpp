#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10;
int dp[2][maxn][maxn], a[maxn], mod;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, b; cin >> n >> m >> b >> mod;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i <= b; ++i) dp[0][0][i] = 1;
    int cur = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= b; ++k) {
                dp[cur][j][k] = dp[cur ^ 1][j][k];
                if (j && k - a[i] >= 0) dp[cur][j][k] = (dp[cur][j][k] + dp[cur][j - 1][k - a[i]]) % mod;
            }
        }
        cur ^= 1;
    }
    cout << dp[cur ^ 1][m][b] << endl;
    return 0;
}