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

const int MAXN = 100100;
int n, q; char a[MAXN];

int calc (int x) { if (x <= 1 || x >= n) return 0; return a[x - 1] == 'a' && a[x] == 'b' && a[x + 1] == 'c'; }
int main () {
    n = read(), q = read(); int i, j;
    scanf("%s", a + 1); int ans = 0;
    for (i = 2; i < n; i++) if (calc(i)) ++ans;
    for (i = 1; i <= q; i++) {
        int x = read(); char c[2]; scanf("%s", c);
        ans -= calc(x - 1) + calc(x) + calc(x + 1);
        a[x] = c[0];
        ans += calc(x - 1) + calc(x) + calc(x + 1);
        printf("%d\n", ans);
    }
    return 0;
}