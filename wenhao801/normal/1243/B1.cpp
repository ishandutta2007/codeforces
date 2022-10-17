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

int n;
char a[10010], b[10010];

int main () {
    int i, j;
    int T = read();
    while (T--) {
        n = read();
        scanf("%s", a + 1);
        scanf("%s", b + 1);
        int x = 0, y = 0;
        for (i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                if (x == 0) x = i;
                else if (y == 0) y = i;
                else break;
            }
        }
        if (i != n + 1 || (y == 0 && x != 0)) { puts("No"); continue; }
        swap(a[x], b[y]); x = 0;
        for (i = 1; i <= n; i++) if (a[i] != b[i]) { x = 1; break; }
        if (x == 1) puts("No"); else puts("Yes");
    }
    return 0;
}