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

const int MAXN = 100100;
int n; char a[MAXN], b[MAXN];

int main () {
    int T = read();
    while (T--) {
        n = read(); int i, j; scanf("%s%s", a + 1, b + 1);
        int ans = 1e9 + 7, s = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
        for (i = 1; i <= n; i++) s += a[i] == b[i], s1 += a[i] == '0' && b[i] == '0', s2 += a[i] == '1' && b[i] == '1',
            s3 += a[i] == '0' && b[i] == '1', s4 += a[i] == '1' && b[i] == '0';
        if ((s & 1) && s2 == s1 + 1) ans = min(s, ans);
        if ((n - s) % 2 == 0 && s3 == s4) ans = min(ans, n - s);
        printf("%d\n", ans > 1e9 ? -1 : ans);
    }
    return 0;
}