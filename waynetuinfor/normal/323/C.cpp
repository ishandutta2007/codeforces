#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn], b[maxn], pa[maxn], pb[maxn];
int segt[maxn], lc[maxn * 40], rc[maxn * 40], sum[maxn * 40];

inline int gtx() {
    const int N = 1048576;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline bool rit(T& x) {
    char c = 0; bool flag = false;
    while (c = getchar(), (c < '0' && c != '-') || c > '9') if (c == -1) return false;
    c == '-' ? (flag = true, x = 0) : (x = c - '0');
    while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

int newnode() {
    static int ptr = 0;
    return ptr++;
}

int build(int l, int r) {
    int o = newnode();
    int m = l + r >> 1;
    if (l == r) lc[o] = rc[o] = -1, sum[o] = 0;
    else lc[o] = build(l, m), rc[o] = build(m + 1, r);
    return o;
}

void pull(int o) { sum[o] = sum[lc[o]] + sum[rc[o]]; }

int modify(int o, int l, int r, int p, int v) {
    int ret = newnode(); 
    lc[ret] = lc[o]; rc[ret] = rc[o]; sum[ret] = sum[o];
    if (l == r) return sum[ret] += v, ret;
    int m = l + r >> 1;
    if (p <= m) lc[ret] = modify(lc[o], l, m, p, v);
    else rc[ret] = modify(rc[o], m + 1, r, p, v);
    return pull(ret), ret;
}

int query(int o, int l, int r, int ql, int qr) {
    if (l > qr || ql > r) return 0;
    if (l >= ql && r <= qr) return sum[o];
    int m = l + r >> 1;
    return query(lc[o], l, m, ql, qr) + query(rc[o], m + 1, r, ql, qr);
}

int main() {
    int n; rit(n);
    for (int i = 1; i <= n; ++i) rit(a[i]), pa[a[i]] = i;
    for (int i = 1; i <= n; ++i) rit(b[i]), pb[b[i]] = i;
    segt[0] = build(1, n);
    for (int i = 1; i <= n; ++i) segt[i] = modify(segt[i - 1], 1, n, pb[a[i]], 1);
    int x = 0;
    auto f = [&x, n](const int &y) { return (y - 1 + x) % n + 1; };
    int q; rit(q); while (q--) {
        int a, b, c, d; rit(a, b, c, d);
        int l1 = min(f(a), f(b)), r1 = max(f(a), f(b));
        int l2 = min(f(c), f(d)), r2 = max(f(c), f(d));
        printf("%d\n", ((x = (query(segt[r1], 1, n, l2, r2) - query(segt[l1 - 1], 1, n, l2, r2)))++));
    }
    return 0;
}