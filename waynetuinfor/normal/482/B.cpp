#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, bit = 30;
int l[maxn], r[maxn], q[maxn], a[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    int val;
    SegmentTree *lc, *rc;
    SegmentTree(int L, int R) {
        val = 0; lc = rc = nullptr;
        if (L == R) {
            val = a[L];
            return;
        }
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        val = lc->val & rc->val;
    }
    int query(int L, int R, int l, int r) {
        if (L > r || l > R) return (1 << bit) - 1;
        if (L >= l && R <= r) return val;
        return lc->query(L, M, l, r) & rc->query(M + 1, R, l, r);
    }
#undef M
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) cin >> l[i] >> r[i] >> q[i];
    for (int b = 0; b < bit; ++b) {
        vector<int> s(maxn, 0);
        for (int i = 0; i < m; ++i) if ((1 << b) & q[i]) ++s[l[i]], --s[r[i] + 1];
        for (int i = 1; i < maxn; ++i) s[i] += s[i - 1];
        for (int i = 1; i <= n; ++i) if (s[i] > 0) a[i] += (1 << b);
    }
    st = new SegmentTree(1, n);
    for (int i = 0; i < m; ++i) {
        if (st->query(1, n, l[i], r[i]) != q[i]) return cout << "NO" << endl, 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << endl;
    return 0;
}