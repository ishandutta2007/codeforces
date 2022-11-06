#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    static SegmentTree mem[800000];
    static SegmentTree *ptr;
    SegmentTree *lc, *rc;
    int val, d;
    SegmentTree() {}
    SegmentTree(int L, int R, int dep) {
        lc = rc = nullptr;
        val = 0; d = dep;
        if (L == R) return;
        lc = new (ptr++) SegmentTree(L, M, dep + 1); rc = new SegmentTree(M + 1, R, dep - 1);
        pull();
    }
    void pull() {
        if (d & 1) val = lc->val | rc->val;
        else val = lc->val ^ rc->val;
    }
    void modify(int L, int R, int x, int v) {
        if (L == R) return val = v, void();
        if (x <= M) lc->modify(L, M, x, v);
        else rc->modify(M + 1, R, x, v);
        pull();
    }
} *st, SegmentTree::mem[800000], *SegmentTree::ptr = mem;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= (1 << n); ++i) cin >> a[i];
    st = new (SegmentTree::ptr++) SegmentTree(1, (1 << n), n);
    for (int i = 1; i <= (1 << n); ++i) st->modify(1, (1 << n), i, a[i]);
    while (m--) {
        int p, v; cin >> p >> v;
        st->modify(1, (1 << n), p, v);
        cout << st->val << endl;
    }
    return 0;
}