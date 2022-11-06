#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const long long inf = 1e18;
int c[maxn], v[maxn];
long long dp[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];
    while (q--) {
        int a, b; cin >> a >> b;
        fill(dp, dp + maxn, -inf);
        dp[0] = 0;
        pair<long long, int> m1 = make_pair(0, 0), m2 = make_pair(-inf, 1);
        for (int i = 1; i <= n; ++i) {
            long long ndp = dp[c[i]] + v[i] * 1ll * a;
            if (c[i] == m1.second) ndp = max(ndp, m2.first + v[i] * 1ll * b);
            else ndp = max(ndp, m1.first + v[i] * 1ll * b);
            dp[c[i]] = max(dp[c[i]], ndp);
            if (c[i] == m1.second || c[i] == m2.second) {
                if (c[i] == m1.second) m1.first = max(m1.first, dp[c[i]]);
                else {
                    m2.first = max(m2.first, dp[c[i]]);
                    if (m1 < m2) swap(m1, m2);
                }
                continue;
            }
            if (dp[c[i]] > m1.first) m2 = m1, m1 = make_pair(dp[c[i]], c[i]);
            else if (dp[c[i]] > m2.first) m2 = make_pair(dp[c[i]], c[i]);
        }
        cout << *max_element(dp, dp + n + 1) << '\n';
    }
    return 0;
}