#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], o[maxn];
long long s[maxn];

int main() {
    int n, amax, cf, cm;
    long long m;
    scanf("%d %d %d %d %lld", &n, &amax, &cf, &cm, &m);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    iota(o, o + n, 0);
    sort(o, o + n, [&](const int &i, const int &j) { return a[i] > a[j]; });
    s[0] = a[o[0]];
    for (int i = 1; i < n; ++i) s[i] = s[i - 1] + a[o[i]];
    long long ans = -1, q = 0;
    int p = -1;
    if (amax * 1ll * n - s[n - 1] <= m) {
        printf("%lld\n", n * 1ll * cf + amax * 1ll * cm);
        for (int i = 0; i < n; ++i) printf("%d ", amax);
        puts("");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        long long z = m - (amax * 1ll * i - q);
        if (z < 0) break;
        int d = 31, l = n;
        while (d--) if (l - (1 << d) >= i) {
            int c = n - (l - (1 << d));
            long long k = s[n - 1] - (l - (1 << d) == 0 ? 0 : s[l - (1 << d) - 1]);
            if (z >= c * 1ll * a[o[l - (1 << d)]] - k) l -= (1 << d);
        }
        if (l == n) continue;
        int t = a[o[l]] + (z - ((n - l) * 1ll * a[o[l]] - (s[n - 1] - (l == 0 ? 0 : s[l - 1])))) / (n - l);
        t = min(t, amax);
        long long r = i * 1ll * cf + t * 1ll * cm;
        if (r > ans) ans = r, p = i;
        q += a[o[i]];
    } 
    assert(p != -1);
    int d = 31, l = n;
    long long z = m - (amax * 1ll * p - (p == 0 ? 0 : s[p - 1])); 
    while (d--) if (l - (1 << d) >= p) {
        int c = n - (l - (1 << d));
        long long k = s[n - 1] - (l - (1 << d) == 0 ? 0 : s[l - (1 << d) - 1]);
        if (z >= c * 1ll * a[o[l - (1 << d)]] - k) l -= (1 << d);
    }
    for (int i = 0; i < p; ++i) a[o[i]] = amax;
    int t = a[o[l]] + (z - ((n - l) * 1ll * a[o[l]] - (s[n - 1] - (l == 0 ? 0 : s[l - 1])))) / (n - l);
    t = min(t, amax);
    for (int i = l; i < n; ++i) a[o[i]] = t;
    printf("%lld\n", ans);
    for (int i = 0; i < n; ++i) printf("%d ", a[i]); puts("");
    return 0;
}