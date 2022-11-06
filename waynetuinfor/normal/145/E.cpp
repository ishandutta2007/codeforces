#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    static SegmentTree mem[4000000];
    static SegmentTree *ptr;
    SegmentTree *lc, *rc;
    int tag, cnt[2], incr, decr;
    SegmentTree() {}
    SegmentTree(int L, int R) {
        tag = 0; cnt[0] = cnt[1] = 0;
        incr = decr = 0;
        if (L == R) {
            ++cnt[a[L]];
            incr = decr = 1;
            return;
        }
        lc = new (ptr++) SegmentTree(L, M); rc = new (ptr++) SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        for (int i = 0; i < 2; ++i) cnt[i] = lc->cnt[i] + rc->cnt[i];
        incr = max({ lc->incr, rc->incr, lc->cnt[0] + rc->incr, lc->incr + rc->cnt[1] });
        decr = max({ lc->decr, rc->decr, lc->cnt[1] + rc->decr, lc->decr + rc->cnt[0] });
    }
    void modify(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            tag ^= 1;
            swap(cnt[0], cnt[1]); swap(incr, decr);
            return;
        }
        lc->modify(L, M, l, r); rc->modify(M + 1, R, l, r);
        pull();
    }
    void push() {
        if (tag == 0 || lc == nullptr) return;
        swap(lc->cnt[0], lc->cnt[1]); swap(lc->incr, lc->decr); lc->tag ^= 1;
        swap(rc->cnt[0], rc->cnt[1]); swap(rc->incr, rc->decr); rc->tag ^= 1;
        tag = 0;
    }
    int query(int L, int R, int l, int r, int &c0, int &c1) {
        push();
        if (L > r || l > R) return (c0 = 0, c1 = 0), 0;
        if (L >= l && R <= r) return (c0 = cnt[0], c1 = cnt[1]), incr;
        int lc0, lc1, rc0, rc1;
        int ql = lc->query(L, M, l, r, lc0, lc1), qr = rc->query(M + 1, R, l, r, rc0, rc1);
        return (c0 = lc0 + rc0, c1 = lc1 + rc1), max({ ql, qr, lc0 + qr, ql + rc1 });
    }
#undef M
} *st, SegmentTree::mem[4000000], *SegmentTree::ptr = mem;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    for (int i = 1; i <= n; ++i) a[i] = (s[i - 1] == '4' ? 0 : 1);
    st = new (SegmentTree::ptr++) SegmentTree(1, n);
    while (m--) {
        string cmd; cin >> cmd;
        if (cmd[0] == 's') {
            int l, r; cin >> l >> r;
            st->modify(1, n, l, r);
        } else {
            int c0, c1;
            cout << st->query(1, n, 1, n, c0, c1) << endl;
        }
    }
    return 0;
}