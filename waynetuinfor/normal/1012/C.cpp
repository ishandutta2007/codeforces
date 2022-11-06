#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
const int inf = 1e9;
int a[maxn];
int dp[maxn][maxn][3];
// 0: no build, 1: build, 2: a[i] = a[i - 1] - 1

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    a[0] = a[n + 1] = -1e7;
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) {
        for (int k = 0; k < 3; ++k) dp[i][j][k] = inf;
    }
    dp[0][0][0] = 0;
    int tg = 0;
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 0; j <= i; ++j) {
            tg = max(0, a[i - 1] - (a[i] - 1));
            if (j) dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - 1][0] + tg);
            if (j && i - 2 >= 0) {
                tg = max(0, a[i - 2] - 1 - (a[i] - 1));
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - 1][2] + tg);
            }
            if (a[i] < a[i - 1]) dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1]);
            dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][2]);
            dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0]);
            tg = max(0, a[i] - (a[i - 1] - 1));
            dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j][1] + tg);
            dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j][0] + tg);
        }
    }
    for (int i = 1; i <= (n + 1) / 2; ++i) printf("%d ", dp[n + 1][i][0]);
    puts("");
}