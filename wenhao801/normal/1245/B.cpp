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

char a[101];
char ans[101];

int main () {
    int T = read();
    while (T--) {
        int n = read();
        int r = read(), p = read(), s = read();
        int i, j;
        scanf("%s", a + 1);
        for (i = 1; i <= n; i++) ans[i] = ' ';
        int win = 0, lose = 0;
        for (i = 1; i <= n; i++) {
            if (r > 0 && a[i] == 'S') r--, ans[i] = 'R', win++;
            if (p > 0 && a[i] == 'R') p--, ans[i] = 'P', win++;
            if (s > 0 && a[i] == 'P') s--, ans[i] = 'S', win++;
        }
        for (i = 1; i <= n; i++) {
            if (r > 0 && a[i] == 'R' && ans[i] == ' ') r--, ans[i] = 'R';
            if (p > 0 && a[i] == 'P' && ans[i] == ' ') p--, ans[i] = 'P';
            if (s > 0 && a[i] == 'S' && ans[i] == ' ') s--, ans[i] = 'S';
        }
        for (i = 1; i <= n; i++) {
            if (a[i] == 'R' && ans[i] == ' ') ans[i] = 'S', lose++;
            if (a[i] == 'P' && ans[i] == ' ') ans[i] = 'R', lose++;
            if (a[i] == 'S' && ans[i] == ' ') ans[i] = 'P', lose++;
        }
        if (win >= (n + 1) / 2) {
            puts("YES");
            for (i = 1; i <= n; i++) printf("%c", ans[i]); putchar('\n');
        }
        else {
            puts("NO");
        }
    }
    return 0;
}