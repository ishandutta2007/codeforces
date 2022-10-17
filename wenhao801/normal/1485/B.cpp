#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define int long long
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n, q, k;
const int MAXN = 100100;
int a[MAXN], b[MAXN];

signed main () {
    n = read(), q = read(), k = read();
    int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    for (i = 2; i <= n; i++) {
        b[i] += a[i] - a[i - 1] - 1;
        b[i] += a[i + 1] - a[i] - 1;
    }
    for (i = 2; i <= n; i++) b[i] += b[i - 1];
    while (q--) {
        int L = read(), R = read(); 
        if (L == R) { printf("%lld\n", k - 1); continue; }
        long long ans = a[L] - 1 + a[L + 1] - a[L] - 1;
        ans += k - a[R - 1] - 1;
        ans += b[R - 1] - b[L];
        printf("%lld\n", ans);
    }
    return 0;
}