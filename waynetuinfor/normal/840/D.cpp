#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int a[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int cnt;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        cnt = 0;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        cnt = lc->cnt + rc->cnt;
    }
    SegmentTree(SegmentTree *t) {
        lc = t->lc; rc = t->rc;
        cnt = t->cnt;
    } 
    SegmentTree *modify(int L, int R, int x) {
        SegmentTree *ret = new SegmentTree(this);
        if (L == R) {
            ++ret->cnt;
            return ret;
        }
        if (x <= M) ret->lc = lc->modify(L, M, x);
        else ret->rc = rc->modify(M + 1, R, x);
        ret->pull();
        return ret;
    }
    int query(int L, int R, int x) {
        if (L == R) return cnt;
        if (x <= M) return lc->query(L, M, x);
        else return rc->query(M + 1, R, x);
    }
#undef M
} *st[maxn];

int solve(SegmentTree *l, SegmentTree *r, int L, int R, int t) {
    if (L == R) return L;
    int M = (L + R) >> 1;
    int q = r->lc->cnt - l->lc->cnt; 
    if (q >= t) return solve(l->lc, r->lc, L, M, t);
    else return solve(l->rc, r->rc, M + 1, R, t - q);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    st[0] = new SegmentTree(1, n);
    for (int i = 1; i <= n; ++i) st[i] = st[i - 1]->modify(1, n, a[i]);
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        int t = (r - l + 1) / k; 
        if (t == 0) {
            cout << solve(st[l - 1], st[r], 1, n, 1) << endl;
            continue;
        }
        int ans = -1;
        for (int ti = t; ; ti += t) {
            if (ti + 1 > r - l + 1) break;
            int pos = solve(st[l - 1], st[r], 1, n, ti + 1);
            if ((st[r]->query(1, n, pos) - st[l - 1]->query(1, n, pos)) * k > r - l + 1) {
                ans = pos;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}