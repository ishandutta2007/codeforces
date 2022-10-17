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

int n, x, a[110];

int main () {
    int T = read();
    while (T--) {
        n = read(); int i,j , s =0;
        x = read(); for (i = 1; i <= n; i++) a[i] = read(), s += a[i];
        if (s == x) { puts("NO"); continue; }
        puts("YES");
        for (i = 1; i < n; i++) {
            x -= a[i];
            if (!x) { swap(a[i], a[i + 1]); break; }
        }
        for (i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
    }
    return 0;
}