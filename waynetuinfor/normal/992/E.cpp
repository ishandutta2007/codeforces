#include <bits/stdc++.h>
using namespace std;
#define getchar gtx

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
    char __c = 0; bool flag = false;
    while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
    __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
    while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

const int maxn = 2e5 + 5;
int a[maxn];
long long s[maxn];

namespace segtree {
    long long lo[maxn * 4], hi[maxn * 4], tg[maxn * 4];
    void init(int l, int r, int o = 0) {
        tg[o] = 0;
        if (r - l == 1) return lo[o] = hi[o] = a[l] - (l ? s[l - 1] : 0), void();
        init(l, (l + r) / 2, o * 2 + 1);
        init((l + r) / 2, r, o * 2 + 2);
        lo[o] = min(lo[o * 2 + 1], lo[o * 2 + 2]);
        hi[o] = max(hi[o * 2 + 1], hi[o * 2 + 2]);
    }
    void push(int o) {
        if (tg[o] == 0) return;
        tg[o * 2 + 1] += tg[o], lo[o * 2 + 1] += tg[o], hi[o * 2 + 1] += tg[o];
        tg[o * 2 + 2] += tg[o], lo[o * 2 + 2] += tg[o], hi[o * 2 + 2] += tg[o];
        tg[o] = 0;
    }
    void modify(int l, int r, int ql, int qr, int v, int o = 0) {
        if (r - l > 1) push(o); 
        if (l >= qr || ql >= r) return;
        if (l >= ql && r <= qr) return lo[o] += v, hi[o] += v, tg[o] += v, void();
        modify(l, (l + r) / 2, ql, qr, v, o * 2 + 1);
        modify((l + r) / 2, r, ql, qr, v, o * 2 + 2);
        lo[o] = min(lo[o * 2 + 1], lo[o * 2 + 2]);
        hi[o] = max(hi[o * 2 + 1], hi[o * 2 + 2]);
    }
    int query(int l, int r, int o = 0) {
        if (r - l > 1) push(o);
        if (lo[o] > 0 || hi[o] < 0) return -1;
        if (r - l == 1) return lo[o] == 0 ? l : -1;
        int c = query(l, (l + r) / 2, o * 2 + 1);
        if (~c) return c;
        c = query((l + r) / 2, r, o * 2 + 2);
        return c;
    }
}

int main() {
    int n, q; rit(n, q);
    for (int i = 0; i < n; ++i) {
        rit(a[i]);
        s[i] = (i ? s[i - 1] : 0) + a[i];
    }
    segtree::init(0, n);
    while (q--) {
        int p, x; rit(p, x); --p;
        segtree::modify(0, n, p, p + 1, x - a[p]);
        segtree::modify(0, n, p + 1, n, a[p] - x);
        a[p] = x;
        int ans = segtree::query(0, n);
        ans += (ans >= 0);
        printf("%d\n", ans);
    }
    return 0;
}