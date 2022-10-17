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
int a[110][110];

int main () {
    int t = read();
    while (t--) {
        int n = read(), m = read(), i, j;
        for (i = 1; i <= n; i++) for (j = 1; j <= m; j++ )a[i][j] = read();
        for (i = 1; i <= n; i++) {for (j = 1; j <= m; j++) {
            if (((i & 1) + (j & 1)) % 2) {
                if (a[i][j] & 1) ++a[i][j];
            }
            else {
                if (a[i][j] % 2 == 0) ++a[i][j];
            }
            printf("%d ", a[i][j]);
        } puts(""); }
    }
    return 0;
}