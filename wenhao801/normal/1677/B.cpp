#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1e6 + 10;
int n, m, ans1[MAXN], ans2[MAXN], ans[MAXN]; char s[MAXN];

int main () {
    int T = read();
    while (T--) {
        n = read(), m = read(); int i, j;
        scanf("%s", s);
        for (i = 0; i < m && s[i] == '0'; i++);
        int now = min(m - 1, i);
        for (i = 0; i < n; i++) for (j = 0; j < now; j++) --ans[i * m + j];
        
        for (i = 0, j = 0; i < n * m; i++) {
            if (s[i] == '0') ++j; else j = 0;
            if (j >= m) --ans1[i];
        }
        for (i = 0; i < n * m; i++) if (i >= m) ans1[i] += ans1[i - m];
        for (i = 0; i < m; i++) {
            --ans2[i];
            for (j = 0; j < n && s[i + j * m] == '0'; j++);
            if (i + j * m < n * m) ++ans2[i + j * m];
        }
        for (i = 1; i < n * m; i++) ans2[i] += ans2[i - 1];
        for (i = 0; i < n * m; i++) printf("%d ", (i / m + 1) + min(m, i + 1) + ans1[i] + ans2[i] + ans[i]), ans1[i] = ans2[i] = ans[i] = 0;
        putchar('\n');
    }
    return 0;
}