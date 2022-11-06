#include <bits/stdc++.h>
#define getchar gtx
#define int long long
using namespace std;

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

const int maxn = 3e5 + 10, inf = 1e18;
int a[maxn];

struct data {
    int len, lans, rans, ans, lpos, lneg, rpos, rneg;
    data() {}
    data(int v) {
        len = 1;
        lans = rans = ans = (v != 0);
        lpos = rpos = (v > 0); lneg = rneg = (v < 0);
    }
    data operator+(const data &d) const {
        data ret; ret.len = len + d.len;
        {
            ret.lpos = (lpos == len ? lpos + d.lpos : lpos);
            ret.lneg = (lneg == len ? lneg + d.lneg : lneg);
            ret.rpos = (d.rpos == d.len ? d.rpos + rpos : d.rpos);
            ret.rneg = (d.rneg == d.len ? d.rneg + rneg : d.rneg);
        }
        {
            ret.lans = max(ret.lpos, ret.lneg);
            ret.rans = max(ret.rpos, ret.rneg);
            (len == lans) ? ret.lans = max(ret.lans, lans + d.lneg) : ret.lans = max(ret.lans, lans);
            if (lpos == len) ret.lans = max(ret.lans, lpos + d.lans);
            (d.len == d.rans) ? ret.rans = max(ret.rans, d.rans + rpos) : ret.rans = max(ret.rans, d.rans);
            if (d.rneg == d.len) ret.rans = max(ret.rans, d.rneg + rans);
        }
        {
            ret.ans = max(ret.lans, ret.rans);
            ret.ans = max(ret.ans, rpos + d.lneg);
            ret.ans = max(ret.ans, rneg + d.lneg); ret.ans = max(ret.ans, rpos + d.lpos);
            ret.ans = max(ret.ans, rpos + d.lans); ret.ans = max(ret.ans, d.lneg + rans);
            ret.ans = max(ret.ans, max(ans, d.ans));
        }
        return ret;
    }
};

struct segtree {
#define M ((L + R) >> 1)
    segtree *lc, *rc;
    data val;
    void pull() { val = lc->val + rc->val; }
    segtree(int L, int R) {
        lc = rc = nullptr; val = data();
        if (L == R) { val = data(a[L]); return; }
        lc = new segtree(L, M); rc = new segtree(M + 1, R);
        pull();
    }
    void modify(int L, int R, int p, int v) {
        if (L == R) return (a[L] += v, val = data(a[L])), void();
        if (p <= M) lc->modify(L, M, p, v);
        else rc->modify(M + 1, R, p, v);
        pull();
    }
#undef M
} *st;

int32_t main() {
    int n; rit(n);
    for (int i = 1; i <= n; ++i) rit(a[i]);
    a[0] = inf;
    for (int i = n; i >= 1; --i) a[i] -= a[i - 1];
    if (n == 1) {
        int m; rit(m); while (m--) puts("1");
        return 0;
    }
    st = new segtree(2, n);
    int m; rit(m); while (m--) {
        int l, r, d; rit(l, r, d);
        if (l > 1) st->modify(2, n, l, d);
        if (r < n) st->modify(2, n, r + 1, -d);
        printf("%I64d\n", st->val.ans + 1);
    }
    return 0;
}