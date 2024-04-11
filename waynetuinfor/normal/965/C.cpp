#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-9;
int main() {
    long long n, k, m, d; scanf("%lld %lld %lld %lld", &n, &k, &m, &d);
    long long ans = 0;
    for (long long i = 1ll; i <= d; ++i) {
        function<bool(long long)> check = [&](long long t) {
            return t * 1.0 * (k * 1.0 * (i - 1) + 1) <= 1.0 * n && t * (k * (i - 1) + 1) <= n;
        };
        long double l = (1.0 * n / (k * 1.0 * i + 1));
        if (l > m) continue;
        long long ll = (long long)l;
        int b = 60;
        while (b--) if (ll + (1ll << b) <= m) {
            if (check(ll + (1ll << b))) ll += (1ll << b);
        }
        if (!check(ll)) continue;
        // printf("i = %lld ll = %lld t = %.lf\n", i, ll, ll * 1.0 * (k * 1.0 * (i - 1) + 1));
        ans = max(ans, ll * i);
    }
    printf("%lld\n", ans);
    return 0;
}