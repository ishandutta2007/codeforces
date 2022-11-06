#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
const long long inf = 1e15 + 1;
int t[maxn], n, k;

struct result {
    long long v, m;
    bool operator<(const result &r) const { return v == r.v ? m < r.m : v < r.v; }
    bool operator>(const result &r) const { return v == r.v ? m > r.m : v > r.v; }
    result operator+(const result &r) const { return (result){ v + r.v, m + r.m }; }
};

result dp[maxn];

result check(long long c) {
    for (int i = 1; i < maxn; ++i) dp[i].v = inf;
    dp[0] = { 0, 0 };
    result r = { inf, inf };
    for (int i = 1; i <= n; ++i) {
        dp[i] = min(dp[i - 1], r + (result){ t[i] - c, 1 });
        r = min(r, dp[i - 1] + (result){ -t[i], 0 });
    }
    return dp[n];
}

int main() {
    scanf("%d %d", &k, &n);
    for (int i = 1; i <= n; ++i) scanf("%d", t + i);
    sort(t + 1, t + n + 1);
    int d = 61, c = 0;
    while (d--) if (c + (1ll << d) < inf) {
        result r = check(c + (1ll << d));
        // printf("c = %lld k = %lld dp = %lld\n", c + (1ll << d), r.m, r.v);
        if (r.m == k) {
            printf("%lld\n", r.v + k * (c + (1ll << d)));
            return 0;
        }
        if (r.m < k) c += (1ll << d);
    }
    // printf("c = %lld\n", c);
    result ra = check(c), rb = check(c + 1);
    long long a = ra.v + ra.m * c, b = rb.v + rb.m * (c + 1);
    // printf("a = %lld b = %lld\n", a, b);
    printf("%lld\n", a + (k - ra.m) * (b - a) / (rb.m - ra.m));
    return 0;
}