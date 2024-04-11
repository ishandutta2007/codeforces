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
int n, m, a[MAXN], fir[MAXN], las[MAXN];

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= m; i++) a[i] = read();
    for (i = 1; i <= n; i++) fir[i] = m + 1, las[i] = 0;
    for (i = 1; i <= m; i++) {
        if (m + 1 == fir[a[i]]) fir[a[i]] = i;
    }
    for (i = m; i >= 1; i--) if (!las[a[i]]) las[a[i]] = i;
    int ans = 0;
    for (i = 1; i <= n; i++) if (!las[i]) ++ans;
    for (i = 1; i < n; i++) if (fir[i] > las[i + 1]) ++ans;
    for (i = 2; i <= n; i++) if (fir[i] > las[i - 1]) ++ans;
    printf("%d\n", ans);
    return 0;
}