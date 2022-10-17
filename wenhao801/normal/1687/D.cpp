#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
const int MAXN = 1001000;
int n; ll a[MAXN];

int main () {
    n = read(); ll i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    a[n + 1] = 1e18;
    for (i = 1; i <= a[n] + 5; i++) {
        if (i * i + i < a[1]) continue;
        const ll add = max(0ll, i * i - a[1]);
        ll L = add, R = i * i + i - a[1];
        for (j = i; j * j - i * i <= a[n] + 5; j++) {
            ll l = j * j, r = j * j + j, val = *(upper_bound(a + 1, a + n + 1, r - add) - 1);
            if (val + add >= l) R = min(R, r - val);
            l = r + 1, r = (j + 1) * (j + 1) - 1, val = *lower_bound(a + 1, a + n + 1, l - add);
            if (val + add <= r) L = max(L, r + 1 - val);
        }
        if (L <= R) { printf("%lld\n", L); return 0; }
    }
    return 0;
}