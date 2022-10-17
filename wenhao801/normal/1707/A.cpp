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

int n, q, a[100100]; bool ans[100100];

int main() {
    int T = read(); while (T--) {
        n = read(), q = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read(), ans[i] = 0;
        int cur = 0;
        for (i = n; i >= 1; i--) {
            if (a[i] > cur) { if (cur < q) ++cur, ans[i] = 1; }
            else ans[i] = 1;
        }
        for (i = 1; i <= n; i++) printf("%d", ans[i]); putchar('\n');
    }
    return 0;
}