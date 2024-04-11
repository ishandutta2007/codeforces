#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long LL;
const LL INF = 5e15 + 5;
const int N = 5e5 + 5;
 
struct dat {
    LL num1, num2, sum;
    dat operator+(dat y) const { return {max(num1, y.num1), max(num2, y.num2), max(max(sum, y.sum), num1 + y.num2)}; }
} tr[(1 << 20) + 5];
 
int n, q, l, r, k, x;
LL s[4][N], dp[N], ans;
vector<pair<int, int>> a[N];
 
void upd(int idx, dat x, int l = 1, int r = n, int i = 1) {
    if (l == r) {tr[i] = x; return;}
    int m = l + r >> 1;
    idx <= m ? upd(idx, x, l, m, i << 1) : upd(idx, x, m + 1, r, i << 1 | 1);
    tr[i] = tr[i << 1] + tr[i << 1 | 1];
}
 
dat qry(int l1, int r1, int l2 = 1, int r2 = n, int i = 1) {
    if (l2 >= l1 && r2 <= r1) return tr[i];
    int m = l2 + r2 >> 1;
    dat x1 = l1 <= m ? qry(l1, r1, l2, m, i << 1) : (dat){-INF, -INF, -INF};
    dat x2 = r1 > m ? qry(l1, r1, m + 1, r2, i << 1 | 1) : (dat){-INF, -INF, -INF};
    return x1 + x2;
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> q;
    rep(j, 1, 3) rep(i, 1, n) cin >> x, s[j][i] = s[j][i - 1] + x;
    rep(j, 1, 2) rep(i, 1, n) s[j][i] -= s[j + 1][i - 1];
    rep(i, 1, q) cin >> l >> r >> k, a[r].push_back({l, k});
    ans = dp[0] = -INF;
    rep(r, 1, n) {
        LL num = max(dp[r - 1], s[1][r]);
        upd(r, {num, s[2][r], num + s[2][r]});
        dp[r] = -INF;
        for (auto [l, k] : a[r])
            dp[r] = max(dp[r], qry(l, r).num1 - k), ans = max(ans, qry(l, r).sum - k);
    }
    cout << ans + s[3][n];
    return 0;
}