#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 5;
const int mod = 998244353;
long long dp[2][maxn][maxn];
long long way[maxn], way2[maxn];
// ith cell, longest j, keep k
//
long long fpow(long long a, long long n) {
    long long r = 1;
    for (; n; n >>= 1) {
        if (n & 1) (r *= a) %= mod;
        (a *= a) %= mod;
    }
    return r;
}

int main() {
    int n, k; scanf("%d %d", &n, &k);
    --n;
    dp[0][0][0] = 1;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < maxn; ++j) for (int k = 0; k < maxn; ++k) dp[cur ^ 1][j][k] = 0;
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= i; ++k) if (dp[cur][j][k]) {
                (dp[cur ^ 1][max(j, k + 1)][k + 1] += dp[cur][j][k]) %= mod;
                (dp[cur ^ 1][j][0] += dp[cur][j][k]) %= mod;
            }
        }
        cur ^= 1;
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) (way[i] += dp[cur][i][j]) %= mod;
    }
    ++n;
    long long ans = 1;
    long long inv = fpow(2, mod - 2);
    for (int i = 1; i <= n; ++i) (ans *= 2) %= mod;
    for (int i = 1; i < n; ++i) (ans *= 2) %= mod;
    // for (int i = 0; i <= n; ++i) printf("way2[%d] = %lld\n", i, way2[i]);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) if (i * j >= k) {
            long long w1 = i ? way[i - 1] : 0;
            long long w2 = j ? way[j - 1] : 0;
            long long t = w1 * w2 * 2 % mod;
            // printf("i = %d j = %d t = %lld\n", i, j, t);
            (ans += mod - t) %= mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}