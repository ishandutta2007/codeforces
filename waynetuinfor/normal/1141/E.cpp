#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int d[maxn];

int main() {
    long long h; int n; scanf("%lld%d", &h, &n);
    long long s = 0, dg = 1e18;
    for (int i = 0; i < n; ++i) scanf("%d", &d[i]);
    for (int i = 0; i < n; ++i) {
        s += d[i];
        dg = min(dg, s);
    }
    if (s >= 0 && -dg < h) {
        puts("-1");
        return 0;
    }
    // printf("s = %lld dg = %lld\n", s, dg);
    long long r = (-dg >= h ? 0 : (h + dg) / -s);
    while (-(r * s + dg) < h) ++r;
    long long ans = r * n, sum = s * r;
    for (int i = 0; i < n; ++i) {
        sum += d[i];
        if (-sum >= h) {
            printf("%lld\n", ans + i + 1);
            return 0;
        }
    }
    assert(false);
}