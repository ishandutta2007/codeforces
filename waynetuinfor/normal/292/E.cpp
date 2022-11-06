#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
int a[maxn], b[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int tag, sum;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        sum = 0; tag = -inf;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
    void push(int L, int R) {
        if (!lc || tag == -inf) return;
        lc->sum = (M - L + 1) * tag; lc->tag = tag;
        rc->sum = (R - M) * tag; rc->tag = tag;
        tag = -inf;
    }
    int query(int L, int R, int l, int r) {
        if (L > R) return 0;
        push(L, R);
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return sum;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
    void modify(int L, int R, int l, int r, int x) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            sum = (R - L + 1) * x;
            tag = x;
            return;
        }
        lc->modify(L, M, l, r, x); rc->modify(M + 1, R, l, r, x);
        pull();
    }
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    st = new SegmentTree(1, n + 1);
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y, k; cin >> x >> y >> k;
            int p = st->query(1, n + 1, 1, y - 1), q = st->query(1, n + 1, 1, y + k);
            st->modify(1, n + 1, y, y, x - p);
            st->modify(1, n + 1, y + 1, y + k - 1, 1);
            int tmp = st->query(1, n + 1, 1, y + k - 1);
            st->modify(1, n + 1, y + k, y + k, q - tmp);
        } else {
            int x; cin >> x;
            int ind = st->query(1, n + 1, 1, x);
            // cout << "ind = " << ind << endl;
            if (ind == 0) cout << b[x] << endl;
            else cout << a[ind] << endl;
        }
    }
    return 0;
}