#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int maxt = 100 + 1;
pair<int, int> qr[maxn];
int dp[2][maxt][maxn];

int main() {
    int n, t; scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &qr[i].first, &qr[i].second);
    sort(qr + 1, qr + n + 1, greater<pair<int, int>>());

    for (int i = 0; i < maxt; ++i) {
        for (int j = 0; j < maxn; ++j)
            dp[0][i][j] = -1e9;
    }

    auto upd = [](int &p, int v) { p = max(p, v); };

    dp[0][0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < maxt; ++j) {
            for (int k = 0; k <= n; ++k)
                dp[i & 1][j][k] = -1e9;
        }
        for (int j = 0; j < maxt; ++j) {
            for (int k = 0; k <= n; ++k) {
                if (dp[i & 1 ^ 1][j][k] >= 0) {
                    if (j + 1 < maxt) upd(dp[i & 1 ^ 1][j + 1][min(k * 2, n)], dp[i & 1 ^ 1][j][k]);
                    upd(dp[i & 1][j][k], dp[i & 1 ^ 1][j][k]);
                    if (k > 0 && qr[i].first + j <= t)
                        upd(dp[i & 1][j][k - 1], dp[i & 1 ^ 1][j][k] + qr[i].second);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < maxt; ++i) {
        for (int j = 0; j <= n; ++j)
            ans = max(ans, dp[n & 1][i][j]);
    }
    printf("%d\n", ans);
    return 0;
}