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
int n; char a[1010], b[1010];

int main () {
    int T = read();
    while (T--) {
        n = read(); int m = read(); scanf("%s", a + 1); m = min(n << 1, m);
        while (m--) {
            for (int i = 1; i <= n; i++) if (a[i] == '0' && (i > 1 && a[i - 1] == '1') + (i < n && a[i + 1] == '1') == 1) b[i] = '1';
            for (int i = 1; i <= n; i++) if (a[i] == '0' && b[i] == '1') a[i] = '1', b[i] = '0';
        }
        puts(a + 1);
    }
    return 0;
}