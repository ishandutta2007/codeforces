#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int n, a[maxn], p[maxn], o[maxn];
long double dp[2][maxn][maxn];
long double c, t;

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        scanf("%d%Lf%Lf", &n, &c, &t);
        for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i], &p[i]);
        for (int i = 1; i <= n; ++i) o[i] = i;
        sort(o + 1, o + n + 1, [&](int i, int j) {
            return a[i] < a[j];
        });
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= 1000; ++j) dp[0][i][j] = dp[1][i][j] = 1e9;
        }
        dp[0][0][0] = 0.0;
        int sum = 0;
        long double rat = (long double)1.0 / 0.9;
        for (int i = 1; i <= n; ++i) {
            sum += p[o[i]];
            for (int j = 0; j <= i; ++j) {
                for (int k = 0; k <= sum; ++k) {
                    dp[i & 1][j][k] = dp[i & 1 ^ 1][j][k];
                    if (j > 0 && k >= p[o[i]]) 
                        dp[i & 1][j][k] = min(dp[i & 1][j][k], (dp[i & 1 ^ 1][j - 1][k - p[o[i]]] + a[o[i]]) * rat);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                long double need = dp[n & 1][i][j];
                if (need + i * 10 <= t) ans = max(ans, j);
                long double x = (sqrt(need * c) - 1.0) / c;
                x = max(x, (long double)0.0);
                if (need / ((1.0 + c * x)) + x + i * 10 <= t) ans = max(ans, j);
            }
        }  
        printf("%d\n", ans);
    }
    return 0;
}