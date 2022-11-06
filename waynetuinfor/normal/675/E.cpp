#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const long long inf = 1e18 + 1;

struct SegmentTree {
#define M ((L + R) >> 1)
    long long val = inf;
    SegmentTree *lc, *rc;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        val = min(lc->val, rc->val);
    }
    void modify(int L, int R, int x, long long v) {
        if (L == R) {
            val = min(val, v);
            return;
        }
        if (x <= M) lc->modify(L, M, x, v);
        else rc->modify(M + 1, R, x, v);
        pull();
    }
    long long query(int L, int R, int l, int r) {
        if (L > r || l > R) return inf;
        if (L >= l && R <= r) return val;
        return min(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
#undef M
} *st;

long long dp[maxn];
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n - 1; ++i) cin >> a[i];
    st = new SegmentTree(1, n);
    st->modify(1, n, n, n);
    dp[n] = 0;
    for (int i = n - 1; i >= 1; --i) {
        long long d = st->query(1, n, i + 1, a[i]);
        dp[i] = n - i + d - a[i];
        st->modify(1, n, i, dp[i] + i);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans += dp[i];
    cout << ans << endl;
}