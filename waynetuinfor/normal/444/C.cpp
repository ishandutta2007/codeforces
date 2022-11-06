#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
#define M ((L + R) >> 1)
    long long sum, minv, maxv;
    long long addt, sett;
    SegmentTree *lc, *rc;
    SegmentTree() {}
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        addt = sett = 0;
        sum = maxv = minv = 0;
        if (L == R) {
            maxv = minv = L;
            return;
        }
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        maxv = max(lc->maxv, rc->maxv);
        minv = min(lc->minv, rc->minv);
        sum = lc->sum + rc->sum;
    }
    void modify(int L, int R, int l, int r, int v) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r && minv == maxv) {
            sum += (R - L + 1) * 1ll * abs(v - minv);
            sett = v; addt += abs(v - minv);
            minv = maxv = v;
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    void push(int L, int R) {
        if (L == R) return;
        if (addt > 0) {
            lc->sum += (M - L + 1) * 1ll * addt; lc->addt += addt;
            rc->sum += (R - M) * 1ll * addt, rc->addt += addt;
            addt = 0;
        }
        if (sett > 0) {
            lc->minv = lc->maxv = sett, lc->sett = sett;
            rc->minv = rc->maxv = sett, rc->sett = sett;
            sett = 0;
        }
    }
    long long query(int L, int R, int l, int r) {
        push(L, R);
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return sum;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
#undef M
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    st = new SegmentTree(1, n);
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, x; cin >> l >> r >> x;
            st->modify(1, n, l, r, x);
        } else {
            int l, r; cin >> l >> r;
            cout << st->query(1, n, l, r) << endl;
        }
    }
    return 0;
}