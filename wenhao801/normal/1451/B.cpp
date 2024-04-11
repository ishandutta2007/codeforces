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

int n, m;
const int MAXN = 110;
char a[MAXN];
bool pre[MAXN][2], suf[MAXN][2];

int main () {
    int T = read();
    while (T--) {
        n = read(), m = read();
        int i, j;
        scanf("%s", a + 1);
        memset(pre, 0, sizeof(pre)); memset(suf, 0, sizeof(suf));
        for (i = 1; i <= n; i++) pre[i][0] = (a[i] == '0') || pre[i - 1][0], pre[i][1] = (a[i] == '1') || pre[i - 1][1];
        for (i = n; i >= 1; i--) suf[i][0] = (a[i] == '0') || suf[i + 1][0], suf[i][1] = (a[i] == '1') || suf[i + 1][1];
        while (m--) {
            int l = read(), r = read();
            int x = a[l] - '0', y = a[r] - '0';
            if (pre[l - 1][x] || suf[r + 1][y]) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}