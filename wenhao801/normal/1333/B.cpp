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

int a[100100];
int b[101000];

int main () {
    int T = read();
    while (T--) {
        int n = read();
        int i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        int lm1 = n + 1, l1 = n + 1, l0 = n + 1;
        for (i = 1; i <= n; i++) {
            if (a[i] == -1) lm1 = min(lm1, i);
            if (a[i] == 0) l0 = min(l0, i);
            if (a[i] == 1) l1 = min(l1, i);
        }
        for (i = 1; i <= n; i++) b[i] = read();
        bool ans = true;
        for (i = n; i >= 1; i--) {
            if (b[i] > a[i] && l1 >= i) ans = false;
            if (b[i] < a[i] && lm1 >= i) ans = false;
        }
        if (!ans) { puts("NO"); continue; }
        else puts("YES");
    }
    return 0;
}