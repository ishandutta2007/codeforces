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

const int MAXN = 33;
int n, a[MAXN], b[MAXN], ans[MAXN];

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read(), b[i] = i;
    sort(b + 1, b + n + 1, [](int u, int v) { return a[u] < a[v]; });
    for (i = 2; i <= n; i++) ans[b[i - 1]] = a[b[i]];
    ans[b[n]] = a[b[1]];
    for (i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}