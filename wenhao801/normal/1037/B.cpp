#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n, a[200200], s;

int main() {
    n = read(), s = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (i = 1; i <= (n >> 1); i++) if (a[i] > s) ans += a[i] - s;
    ans += abs(a[(n >> 1) + 1] - s);
    for (i = (n >> 1) + 2; i <= n; i++) if (a[i] < s) ans += s - a[i];
    printf("%lld\n", ans);
    return 0;
}