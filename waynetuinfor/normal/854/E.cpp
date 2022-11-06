#include <bits/stdc++.h>
#define getchar gtx
#define int long long
using namespace std;

const int maxn = 2e5 + 10;
int p[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int cnt;
    SegmentTree(int L, int R) {
        lc = rc = nullptr; cnt = 0;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    SegmentTree(SegmentTree *t) {
        lc = t->lc; rc = t->rc;
        cnt = t->cnt;
    }
    void pull() {
        cnt = lc->cnt + rc->cnt;
    }
    SegmentTree *modify(int L, int R, int x, int v) {
        SegmentTree *t = new SegmentTree(this);
        if (L == R) {
            t->cnt += v;
            return t;
        }
        if (x <= M) t->lc = lc->modify(L, M, x, v);
        else t->rc = rc->modify(M + 1, R, x, v);
        t->pull(); return t;
    }
    int query(int L, int R, int l, int r) {
        if (l > r) return 0;
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return cnt;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
#undef M
} *st[maxn];

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

int32_t main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; rit(n, q);
    for (int i = 1; i <= n; ++i) rit(p[i]);
    st[0] = new SegmentTree(1, n);
    for (int i = 1; i <= n; ++i) st[i] = st[i - 1]->modify(1, n, p[i], 1);
    while (q--) {
        int l, d, r, u; rit(l, d, r, u);
        long long aa = st[l - 1]->query(1, n, 1, d - 1), ab = st[r]->query(1, n, 1, d - 1) - aa, ac = st[n]->query(1, n, 1, d - 1) - aa - ab;
        long long ba = st[l - 1]->query(1, n, d, u), bb = st[r]->query(1, n, d, u) - ba, bc = st[n]->query(1, n, d, u) - ba - bb;
        long long ca = st[l - 1]->query(1, n, u + 1, n), cb = st[r]->query(1, n, u + 1, n) - ca, cc = st[n]->query(1, n, u + 1, n) - ca - cb;
        long long ans = 0;
        ans += aa * (bb + bc + cb + cc) + ba * (ab + bb + cb + ac + bc + cc) + ca * (ab + ac + bb + bc);
        ans += ab * (bb + bc + cb + cc) + bb * (cb + ac + bc + cc) + cb * (ac + bc);
        ans += bb * (bb - 1) / 2;
        printf("%I64d\n", ans);
    }
    return 0;
}