#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int sum, maxv;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        sum = maxv = 0;
        if (L == R) {
            sum = maxv = a[L];
            return;
        }
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        sum = lc->sum + rc->sum;
        maxv = max(lc->maxv, rc->maxv);
    }
    void modify1(int L, int R, int l, int r, int x) {
        if (maxv < x) return;
        if (L > r || l > R) return;
        if (L == R) {
            sum %= x;
            maxv = sum;
            return;
        }
        lc->modify1(L, M, l, r, x); rc->modify1(M + 1, R, l, r, x);
        pull();
    }
    void modify2(int L, int R, int x, int v) {
        if (L == R) {
            sum = maxv = v;
            return;
        }
        if (x <= M) lc->modify2(L, M, x, v);
        else rc->modify2(M + 1, R, x, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return sum;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
#undef M
} *st;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    st = new SegmentTree(1, n);
    while (m--) {
        int t; cin >> t; 
        if (t == 1) {
            int l, r; cin >> l >> r;
            cout << st->query(1, n, l, r) << endl;
        }
        if (t == 2) {
            int l, r, x; cin >> l >> r >> x;
            st->modify1(1, n, l, r, x);
        }
        if (t == 3) {
            int k, x; cin >> k >> x;
            st->modify2(1, n, k, x);
        }
    }
    return 0;
}