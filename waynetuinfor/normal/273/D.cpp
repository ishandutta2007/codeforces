#include <bits/stdc++.h>
using namespace std;

const int maxn = 200, mod = 1e9 + 7;
long long dp[maxn][maxn][maxn][2][2];
long long s[2][2][maxn][maxn];

long long get(long long s[maxn][maxn], int l, int r, int a, int b) {
    long long rt = s[r][b] - s[l - 1][b] - s[r][a - 1] + s[l - 1][a - 1];
    ((rt %= mod) += mod) %= mod;
    return rt;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) dp[1][i][j][1][1] = 1;
    }
    for (int a = 0; a < 2; ++a) for (int b = 0; b < 2; ++b) {
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
            s[a][b][i][j] = s[a][b][i - 1][j] + s[a][b][i][j - 1] - s[a][b][i - 1][j - 1];
            (((s[a][b][i][j] += dp[1][i][j][a][b]) %= mod) += mod) %= mod;
        }
    }
    for (int i = 2; i <= m; ++i) {
        for (int l = 1; l <= n; ++l) {
            for (int r = l; r <= n; ++r) {
                dp[i][l][r][1][1] = (get(s[1][1], l, r, l, r) + 0 * get(s[1][0], l, r, r, r) + 
                                     0 * get(s[0][1], l, l, l, r) + 0 * get(s[0][0], l, l, r, r)) % mod;
                dp[i][l][r][0][0] = (get(s[1][1], 1, l - 1, r + 1, n) + get(s[1][0], 1, l - 1, r, n) + 
                                     get(s[0][1], 1, l, r + 1, n) + get(s[0][0], 1, l, r, n)) % mod;
                dp[i][l][r][0][1] = (get(s[1][1], 1, l - 1, l, r) + 0 * get(s[1][0], 1, l - 1, r, r) + 
                                     get(s[0][1], 1, l, l, r) + 0 * get(s[0][0], l, l, r, r)) % mod;
                dp[i][l][r][1][0] = (get(s[1][1], l, r, r + 1, n) + get(s[1][0], l, r, r, n) +
                                     0 * get(s[0][1], l, l, r + 1, n) + 0 * get(s[0][0], l, l, r, n)) % mod;
                dp[i][l][r][1][1] = (dp[i][l][r][1][1] + 1) % mod;
            }
        }
        memset(s, 0, sizeof(s));
        for (int a = 0; a < 2; ++a) for (int b = 0; b < 2; ++b) {
            for (int l = 1; l <= n; ++l) for (int r = 1; r <= n; ++r) {
                s[a][b][l][r] = s[a][b][l - 1][r] + s[a][b][l][r - 1] - s[a][b][l - 1][r - 1];
                (((s[a][b][l][r] += dp[i][l][r][a][b]) %= mod) += mod) %= mod;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; ++i) for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) (ans += dp[i][l][r][0][0] + dp[i][l][r][0][1] + 
                                             dp[i][l][r][1][0] + dp[i][l][r][1][1]) %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}