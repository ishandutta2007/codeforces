#pragma GCC optimize("Ofast", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
long long s[maxn];
int dp1[maxn], dp2[maxn];
int p[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &s[i]);
    for (int i = 2; i <= n; ++i) scanf("%d", &p[i]);
    for (int i = n; i >= 2; --i) s[p[i]] += s[i];
    for (int i = 1; i <= n; ++i) {
        long long k = s[1] / __gcd(s[i], s[1]);
        if (k <= n) dp1[k]++;
    }
    for (int i = n; i >= 1; --i) {
        for (int j = i + i; j <= n; j += i) dp1[j] += dp1[i];
    }
    dp2[1] = 1;
    for (int i = 1; i <= n; ++i) {
        if (dp1[i] != i) continue;
        for (int j = i + i; j <= n; j += i) (dp2[j] += dp2[i]) %= mod;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp1[i] == i) (ans += dp2[i]) %= mod;
    }
    printf("%d\n", ans);
}