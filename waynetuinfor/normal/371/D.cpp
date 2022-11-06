#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10, maxmem = 1e6 + 10;
int a[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int sum;
    bool tag;
    static SegmentTree mem[maxmem];
    static SegmentTree *ptr;
    SegmentTree() {}
    SegmentTree(int L, int R) {
        lc = rc = nullptr; tag = false;
        if (L == R) {
            sum = a[L];
            return;
        }
        lc = new(ptr++) SegmentTree(L, M); rc = new(ptr++) SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
    void push() {
        if (!lc || !tag) return;
        lc->sum = 0; lc->tag = true;
        rc->sum = 0; rc->tag = true;
        tag = false;;
    }
    void set(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            sum = 0;
            tag = true;
            return;
        }
        lc->set(L, M, l, r); rc->set(M + 1, R, l, r);
        pull();
    }
    void add(int L, int R, int x, int v) {
        if (x > R) return;
        if (L == R) {
            sum += v;
            return;
        }
        if (x <= M) lc->add(L, M, x, v);
        else rc->add(M + 1, R, x, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return sum;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
#undef M
} *st;

SegmentTree SegmentTree::mem[maxmem];
SegmentTree *SegmentTree::ptr = mem;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    st = new(SegmentTree::ptr++) SegmentTree(1, n);
    int m; cin >> m; while (m--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int p, x; cin >> p >> x;
            if (st->query(1, n, p, p) >= x) {
                st->add(1, n, p, -x);
                continue;
            }
            int d = 1, len = 0; while (d <= n) d <<= 1;
            while (d >>= 1) if (p + len + d - 1 <= n) {
                int cap = st->query(1, n, p, p + len + d - 1);
                if (cap < x) len += d;
            }
            int cap = st->query(1, n, p, p + len - 1); 
            assert(cap < x);
            st->set(1, n, p, p + len - 1);
            st->add(1, n, p + len, cap - x);
        } else {
            int k; cin >> k;
            cout << a[k] - st->query(1, n, k, k) << endl;
        }
    }
    return 0;
}