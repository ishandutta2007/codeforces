#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
deque<int> pos[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    static SegmentTree mem[4000000];
    static SegmentTree *ptr;
    SegmentTree *lc, *rc;
    int sum;
    SegmentTree() {}
    SegmentTree(int L, int R) {
        sum = 0;
        lc = rc = nullptr;
        if (L == R) return;
        lc = new (ptr++) SegmentTree(L, M); rc = new (ptr++) SegmentTree(M + 1, R);
    }
    SegmentTree(SegmentTree *t) {
        lc = t->lc; rc = t->rc;
        sum = t->sum;
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
    SegmentTree *modify(int L, int R, int p, int v) {
        SegmentTree *ret = new (ptr++) SegmentTree(this);
        if (L == R) return ret->sum += v, ret;
        if (p <= M) ret->lc = lc->modify(L, M, p, v);
        else ret->rc = rc->modify(M + 1, R, p, v);
        ret->pull();
        return ret;
    }
    int query(int L, int R, int l, int r) {
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return sum;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
#undef M
} *st[maxn], SegmentTree::mem[4000000], *SegmentTree::ptr = mem;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    st[0] = new (SegmentTree::ptr++) SegmentTree(1, n);
    for (int i = 1; i <= n; ++i) {
        st[i] = st[i - 1]->modify(1, n, i, 1);
        pos[a[i]].push_back(i);
        while (pos[a[i]].size() > k) {
            st[i] = st[i]->modify(1, n, pos[a[i]].front(), -1);
            pos[a[i]].pop_front();
        }
    }
    int last = 0;
    int q; cin >> q; while (q--) {
        int l, r; cin >> l >> r;
        l = (l + last) % n + 1; r = (r + last) % n + 1;
        if (l > r) swap(l, r);
        last = st[r]->query(1, n, l, r);
        cout << last << endl;
    }
    return 0;
}