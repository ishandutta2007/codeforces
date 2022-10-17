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
int n, m, a[MAXN];
int pre[MAXN], suf[MAXN];

int t[MAXN];
inline int lowbit (int x) { return x & -x; }
inline int ask (int x) { ++x; int ret = 0; while (x) ret = max(ret, t[x]), x -= lowbit(x); return ret; }
inline void add (int x, int k) { ++x; while (x <= n + 1) t[x] = max(t[x], k), x += lowbit(x); }

int main () {
    m = read(), n = read(); int i, j;
    for (i = 1; i <= m; i++) {
        int l = read(), r = read(); ++a[l], --a[r + 1];
    }
    for (i = 1; i <= n; i++) a[i] += a[i - 1];
    for (i = 1; i <= n; i++) {
        pre[i] = ask(a[i]) + 1;
        add(a[i], pre[i]);
    }
    memset(t, 0, sizeof t);
    for (i = n; i >= 1; i--) {
        suf[i] = ask(a[i]) + 1;
        add(a[i], suf[i]);
    }
    int ans = 0;
    for (i = 1; i <= n; i++) ans = max(ans, pre[i] + suf[i] - 1);
    printf("%d\n", ans);
    return 0;
}