#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;

const int MAXN = 110;
int n, m; ll a[MAXN], fir, sec;

int main () {
    scanf("%d%d", &n, &m); int i, j;
    for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (i = 2; i <= m * 2; i++) {
        if (i % 2 == 0) {
            bool now = 0;
            for (j = 1; j <= n; j++) now ^= (a[j] / (i >> 1)) & 1;
            if (now) ++fir; else ++sec;
        }
        int l = max(1, i - m), r = (i - 1) >> 1;
        int mx1 = 0, mx2 = 0, mx = 0; bool par = 0;
        for (j = 1; j <= n; j++) {
            int val = a[j] % i;
            if (val > (i >> 1)) par ^= 1;
            if (val >= mx1) mx2 = mx1, mx1 = val;
            else if (val >= mx2) mx2 = val;
            mx = max(mx, min(val + 1, i - val));
        }
        l = max(l, max(mx, (mx2 >> 1) + 1));
        if (par) fir += max(0, (mx1 >> 1) - l + 1) * 2;
        l = max(l, (mx1 >> 1) + 1);
        if (par) fir += max(0, r - l + 1) * 2; else sec += max(0, r - l + 1) * 2;
    }
    printf("%lld %lld %lld %lld\n", (1ll * m * m - fir - sec) >> 1, (1ll * m * m - fir - sec) >> 1, fir, sec);
    return 0;
}