#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n, a[200200];

int main () {
    int T = read(); while (T--) {
        int i, j; n = read();
        for (i = 1; i <= n; i++) a[i] = read();
        int l = 0, r = n;
        for (i = 1; i <= n; i++) if (a[i] == a[i + 1]) { l = i; break; }
        for (i = n - 1; i >= 1; i--) if (a[i] == a[i + 1]) { r = i; break; }
        if (l == r || l == 0) { puts("0"); continue; }
        printf("%d\n", max(1, r - l - 1));
    }
    return 0;
}