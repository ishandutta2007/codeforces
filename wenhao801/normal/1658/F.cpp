#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

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
int n, m, s[MAXN]; char a[MAXN];

int main () {
    int T = read();
    while (T--) {
        n = read(), m = read(); int i, j;
        scanf("%s", a + 1);
        for (i = 1; i <= n; i++) s[i] = s[i - 1] + a[i] - '0';
        if (1ll * s[n] * m % n) { puts("-1"); continue; }
        int aim = 1ll * s[n] * m / n;
        for (i = m; i <= n; i++) {
            if (s[i] - s[i - m] == aim) {
                printf("1\n%d %d\n", i - m + 1, i);
                break;
            }
        }
        if (i > n) {
            for (i = 1; i < m; i++) if (s[i] + s[n] - s[n - m + i] == aim) {
                printf("2\n1 %d\n%d %d\n", i, n - m + i + 1, n);
                break;
            }
            assert(i < m);
        }
    }
    return 0;
}