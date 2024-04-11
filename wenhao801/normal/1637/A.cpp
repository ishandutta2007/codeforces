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

const int MAXN = 10100;
int n, a[MAXN], pmx[MAXN];

int main() {
    int T = read(); while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read(), pmx[i] = max(pmx[i - 1], a[i]);
        int mn = 1e9;
        for (i = n; i > 1; i--) {
            mn = min(mn, a[i]);
            if (pmx[i - 1] > mn) { puts("YES"); break; }
        }
        if (i == 1) puts("NO");
    }
    return 0;
}