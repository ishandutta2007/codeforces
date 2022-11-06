#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
const int mod = 1e9 + 123;
int a[maxn], cnt[maxn];
int f[maxn], inv[maxn];
int dp[10][maxn];

int fpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * 1ll * a % mod;
        a = a * 1ll * a % mod;
        n >>= 1;
    }
    return res;
}

int cnk(int n, int k) {
    if (n < k) return 0;
    return f[n] * 1ll * inv[k] % mod * inv[n - k] % mod;
}

int main() {
    f[0] = inv[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        f[i] = f[i - 1] * 1ll * i % mod;
        inv[i] = fpow(f[i], mod - 2);
    }
    int n; scanf("%d", &n);
    int g = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        cnt[a[i]] = 1;
        g = __gcd(g, a[i]);
    }
    if (g != 1) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i < maxn; ++i) {
        for (int j = i + i; j < maxn; j += i) cnt[i] += cnt[j];
    }
    for (int i = maxn - 1; i >= 1; --i) {
        for (int j = 0; j < 10; ++j) {
            dp[j][i] = cnk(cnt[i], j);
            for (int k = i + i; k < maxn; k += i) 
                (dp[j][i] += mod - dp[j][k]) %= mod;
        }
    }
    for (int i = 1; i < 10; ++i) {
        if (dp[i][1]) {
            printf("%d\n", i);
            return 0;
        }
    }
}