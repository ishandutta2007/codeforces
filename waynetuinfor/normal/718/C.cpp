#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
using matrix = pair<pair<int, int>, pair<int, int>>;
const matrix I = { { 1, 0 }, { 0, 1 } };
const matrix O = { { 0, 0 }, { 0, 0 } };
const matrix E = { { 0, 1 }, { 1, 1 } };

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

inline matrix matmul(const matrix &a, const matrix &b) {
    matrix ret = O;
    ret.first.first = add(mul(a.first.first, b.first.first), mul(a.first.second, b.second.first));
    ret.first.second = add(mul(a.first.first, b.first.second), mul(a.first.second, b.second.second));
    ret.second.first = add(mul(a.second.first, b.first.first), mul(a.second.second, b.second.first));
    ret.second.second = add(mul(a.second.first, b.first.second), mul(a.second.second, b.second.second));
    return ret;
}

matrix fpow(matrix a, int n) {
    matrix ret = I;
    for (; n; n >>= 1) {
        if (n & 1) ret = matmul(ret, a);
        a = matmul(a, a);
    }
    return ret;
}

inline matrix matadd(const matrix &a, const matrix &b) {
    matrix ret = O;
    ret.first.first = add(a.first.first, b.first.first);
    ret.first.second = add(a.first.second, b.first.second);
    ret.second.first = add(a.second.first, b.second.first);
    ret.second.second = add(a.second.second, b.second.second);
    return ret;
}

int a[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    static SegmentTree mem[400000];
    static SegmentTree *ptr;
    SegmentTree *lc, *rc;
    matrix val, tag;
    SegmentTree() {}
    SegmentTree(int L, int R) {
        val = O; tag = I;
        lc = rc = nullptr;
        if (L == R) {
            val = fpow(E, a[L] - 1);
            return;
        }
        lc = new (ptr++) SegmentTree(L, M); rc = new (ptr++) SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        val = matadd(lc->val, rc->val);
    }
    void push() {
        if (lc == nullptr || tag == I) return;
        lc->val = matmul(lc->val, tag); lc->tag = matmul(lc->tag, tag);
        rc->val = matmul(rc->val, tag); rc->tag = matmul(rc->tag, tag);
        tag = I;
    }
    void modify(int L, int R, int l, int r, const matrix &x) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            val = matmul(val, x);
            tag = matmul(tag, x);
            return;
        }
        lc->modify(L, M, l, r, x); rc->modify(M + 1, R, l, r, x);
        pull();
    }
    matrix query(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return O;
        if (L >= l && R <= r) return val;
        return matadd(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
#undef M
} *st, SegmentTree::mem[400000], *SegmentTree::ptr = mem;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    st = new (SegmentTree::ptr++) SegmentTree(1, n);
    while (m--) {
        int t, l, r, x; cin >> t >> l >> r;
        if (t == 1) cin >> x, st->modify(1, n, l, r, fpow(E, x));
        else cout << st->query(1, n, l, r).second.second << '\n';
    }
    return 0;
}