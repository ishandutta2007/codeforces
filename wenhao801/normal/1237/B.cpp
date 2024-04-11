#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100100;
int n, p[MAXN], q[MAXN], id[MAXN];

int main() {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) p[read()] = i, id[i] = i;
    for (i = 1; i <= n; i++) q[read()] = i;
    sort(id + 1, id + n + 1, [](int u, int v) { return p[u] < p[v]; });
    int mx = 0, ans = 0;
    for (i = 1; i <= n; i++) ans += q[id[i]] <= mx, mx = max(mx, q[id[i]]);
    printf("%d\n", ans);
    return 0;
}