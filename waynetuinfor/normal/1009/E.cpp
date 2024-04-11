#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const long long mod = 998244353;
long long a[maxn], s[maxn];
long long dp[maxn], pw[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) s[i] = (s[i - 1] + a[i]) % mod;
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * 2 % mod;
    long long z = 0, t = s[1];
    for (int i = 1; i <= n; ++i) {
        dp[i] = (z + t) % mod;
        t = (t - s[i] + mod) * 2 % mod;
        (t += s[i + 1] + s[i]) %= mod;
        (z += dp[i]) %= mod;
    }
    printf("%lld\n", dp[n]);
}