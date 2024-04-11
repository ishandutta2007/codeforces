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

const int MAXN = 200200;
int n, a[MAXN], b[33];

int main() {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) {
        a[i] = read();
        for (j = 0; j < 30; j++) b[j] += (a[i] >> j) & 1;
    }
    long long ans = 0;
    for (i = 1; i <= n; i++) {
        int tmp = 0;
        for (j = 0; j < 30; j++) if (b[j]) --b[j], tmp += 1 << j;
        ans += 1ll * tmp * tmp;
    }
    printf("%lld\n", ans);
    return 0;
}