#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
long long h[maxn];
int dp[maxn], t[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    pair<int, int> val;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        val = max(lc->val, rc->val);
    }
    void modify(int L, int R, int x, pair<int, int> v) {
        if (L == R) { val = max(val, v); return; }
        if (x <= M) lc->modify(L, M, x, v);
        else rc->modify(M + 1, R, x, v);
        pull();
    }
    pair<int, int> query(int L, int R, int l, int r) {
        if (l > r) return make_pair(0, 0);
        if (L > r || l > R) return make_pair(0, 0);
        if (L >= l && R <= r) return val;
        return max(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, d; cin >> n >> d;
    vector<long long> v;
    for (int i = 1; i <= n; ++i) cin >> h[i], v.push_back(h[i]);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    st = new SegmentTree(0, v.size() - 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = 0; t[i] = 0;
        int l = lower_bound(v.begin(), v.end(), h[i] - d) - v.begin(), r = lower_bound(v.begin(), v.end(), h[i] + d) - v.begin();
        while (l >= 0 && abs(v[l] - h[i]) < d) --l;
        while (r < v.size() - 1 && abs(v[r] - h[i]) < d) ++r;
        pair<int, int> p = max(st->query(0, v.size() - 1, 0, l), st->query(0, v.size() - 1, r, v.size() - 1));
        t[i] = p.second; dp[i] = p.first + 1;
        int pos = lower_bound(v.begin(), v.end(), h[i]) - v.begin();
        st->modify(0, v.size() - 1, pos, make_pair(dp[i], i));
    }
    pair<int, int> ans = make_pair(0, 0);
    for (int i = 1; i <= n; ++i) ans = max(ans, make_pair(dp[i], i));
    cout << ans.first << endl;
    stack<int> ind;
    int cur = ans.second;
    while (cur) {
        ind.push(cur); cur = t[cur];
    }
    while (ind.size()) cout << ind.top() << ' ', ind.pop(); cout << endl;
    return 0;
}