#include <bits/stdc++.h>
#define size(t) (t ? t->sz : 0)
using namespace std;

const int maxn = 1e5 + 10;

struct SegmentTree {
#define M ((L + R) >> 1)
    static SegmentTree mem[4000000];
    static SegmentTree *ptr;
    SegmentTree *lc, *rc;
    int sum;
    SegmentTree() {}
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        sum = 0;
        if (L == R) return;
        lc = new (ptr++) SegmentTree(L, M); rc = new (ptr++) SegmentTree(M + 1, R);
        pull();
    }
    SegmentTree(SegmentTree *t) {
        lc = t->lc; rc = t->rc;
        sum = t->sum;
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
    SegmentTree *modify(int L, int R, int x, int v) {
        SegmentTree *ret = new (ptr++) SegmentTree(this);
        if (L == R) return ret->sum += v, ret;
        if (x <= M) ret->lc = lc->modify(L, M, x, v);
        else ret->rc = rc->modify(M + 1, R, x, v);
        return ret->pull(), ret;
    }
    int query(int L, int R, int l, int r) {
        if (l > r) return 0;
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return sum;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
    int find(int L, int R, int t) {
        if (t > sum) return 0;
        if (L == R) return L;
        if (rc->sum >= t) return rc->find(M + 1, R, t);
        else return lc->find(L, M, t - rc->sum);
    }
} *st[maxn], SegmentTree::mem[4000000], *SegmentTree::ptr = mem;

int a[maxn], p[maxn], b[maxn], ans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int bsize = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == a[i - 1]) continue;
        b[++bsize] = a[i];
    }
    st[0] = new (SegmentTree::ptr++) SegmentTree(1, bsize);
    for (int i = 1; i <= bsize; ++i) {
        st[i] = st[i - 1]->modify(1, bsize, i, 1);
        if (p[b[i]]) st[i] = st[i]->modify(1, bsize, p[b[i]], -1);
        p[b[i]] = i;
    }
    for (int k = 1; k <= bsize; ++k) {
        int ptr = bsize; ans[k] = 0;
        while (ptr > 0) {
            int lb = max(1, ptr - k + 1);
            ptr = st[ptr]->find(1, bsize, k + 1);
            ++ans[k];
        }
    }
    for (int i = 1; i <= n; ++i) cout << (ans[i] ? ans[i] : ans[i] + 1) << ' '; cout << endl;
    return 0;
}