#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 1;
struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    pair<int, int> sum;
    int tag;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        sum = make_pair(0, 0); tag = 0;
        if (L == R) {
            sum = make_pair(0, L);
            return;
        }
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        sum = max(lc->sum, rc->sum);
    }
    void push(int L, int R) {
        if (L == R || tag == 0) return;
        lc->sum.first += tag; lc->tag += tag;
        rc->sum.first += tag; rc->tag += tag;
        tag = 0;
    }
    void modify(int L, int R, int l, int r, int v) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            sum.first += v; tag += v;
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    pair<int, int> query(int L, int R, int l, int r) {
        push(L, R);
        if (L > r || l > R) return make_pair(-inf, 0);
        if (L >= l && R <= r) return sum;
        return max(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
} *st, *nst;

const int maxn = 2e5 + 10;
int a[maxn];
pair<int, int> qry[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    st = new SegmentTree(1, n);
    for (int i = 0; i < q; ++i) {
        cin >> qry[i].first >> qry[i].second;
        st->modify(1, n, qry[i].first, qry[i].second, 1);
    }
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = n; i >= 1; --i) {
        auto p = st->query(1, n, 1, n);
        ans += (long long)a[i] * (long long)p.first;
        assert(p.second >= 1);
        st->modify(1, n, p.second, p.second, -inf);
    }
    cout << ans << endl;
}