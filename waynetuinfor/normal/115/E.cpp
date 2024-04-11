#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
int a[maxn], l[maxn], r[maxn], p[maxn], dp[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int val, tag;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        val = tag = 0;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        val = max(lc->val, rc->val);
    }
    void push() {
        if (!lc || tag == 0) return;
        lc->val += tag; lc->tag += tag;
        rc->val += tag; rc->tag += tag;
        tag = 0;
    }
    void modify(int L, int R, int l, int r, int v) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            val += v;
            tag += v;
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return -inf;
        if (L >= l && R <= r) return val;
        return max(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
#undef M
} *st;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
    vector<int> vec;
    for (int i = 1; i <= m; ++i) {
        cin >> l[i] >> r[i] >> p[i];
        vec.push_back(i);
    }
    sort(vec.begin(), vec.end(), [&](const int& i, const int& j) { return r[i] < r[j]; });
    st = new SegmentTree(0, n);
    int ind = 0, curmax = 0;
    for (int i = 1; i <= n; ++i) st->modify(0, n, i, i, a[i]);
    for (int i = 1; i <= n; ++i) {
        while (ind < vec.size() && r[vec[ind]] == i) {
            st->modify(0, n, 0, l[vec[ind]] - 1, p[vec[ind]]);
            ++ind;
        }
        // cout << "modify: " << -a[i] << endl;
        // st->modify(0, n, 0, i, -a[i]);
        // for (int j = 0; j <= i; ++j) cout << "qry(" << j << ") = " << st->query(0, n, j, j) << endl;
        dp[i] = st->query(0, n, 0, i - 1) - a[i];
        // cout << "dp[" << i << "] = " << dp[i] << endl; 
        curmax = max(curmax, dp[i]);
        st->modify(0, n, i, i, curmax);
        // for (int j = 0; j <= i; ++j) cout << "qry(" << j << ") = " << st->query(0, n, j, j) << endl;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}