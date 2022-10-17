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

const int MAXN = 200200;
int n, a[MAXN], b[MAXN], c[MAXN];

int main () {
    int T = read(); while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        for (i = 1; i <= n; i++) b[i] = read();
        bool no = 0;
        b[n + 1] = -1;
        for (i = n, j = n; i >= 1; i--) {
            if (b[i] != b[i + 1]) {
                while (j >= 1 && a[j] != b[i]) {
                    if (c[a[j]]) --c[a[j]], --j;
                    else { no = 1; break; }
                }
                if (a[j] == b[i]) --j; else no = 1;
                if (no) break;
            }
            else ++c[b[i]];
        }
        while (j >= 1) {
            if (c[a[j]]) --c[a[j]], --j;
            else { no = 1; break; }
        }
        if (no) puts("NO"); else puts("YES");
        for (i = 1; i <= n; i++) c[i] = 0;
    }
    return 0;
}