#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int a[101000] = {};
signed main () {
    int n = read(), m = read();
    int i, j;
    for (i = 1, j = 0; i <= m; i++) a[i] = read(), j += a[i];
    if (j < n) {
        puts("-1");
        return 0;
    }
    for (i = 1; i <= m; i++) if (n - a[i] < i - 1) {
        puts("-1");
        return 0;
    }
    for (i = m, j = 0; i + j < n; j += a[i], i--);
    if (n == m) { for (i = 1; i <= n; i++) cout << i << ' '; return 0; }
    for (int k = 1; k <= i + 1; k++) cout << k << ' ';
    j -= a[i + 1];
    for (int k = i + 2; k <= m; k++) cout << n - j + 1 << ' ', j -= a[k];
    return 0;
}