#include <bits/stdc++.h>
using namespace std;
#define REP(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define rep(i, n) REP(i, 0, n)
using ll = long long;
constexpr ll mod = 998244353;

ll dp2[2][444][444][3][3], dp1[2][444][2][2], dp[2];

int main() {
    int n;
    cin >> n;
    {
        dp[0] = 26 * 26;
        REP(i, 2, n) {
            dp[(i + 1) & 1] = dp[i & 1] * 25 % mod;
        }
    }
    {
        int num[] = {1, 25};
        rep(k1, 2) rep(k2, 2) {
            dp1[0][(k1 == 0) + (k2 == 0)][k1][k2] = num[k1] * num[k2];
        }
        REP(i, 2, n) {
            rep(j, n + 1) rep(k1, 2) rep(k2, 2) {
                dp1[(i + 1) & 1][j][k1][k2] = 0;
            }
            rep(j, n + 1) rep(k1, 2) rep(k2, 2) {
                dp1[i & 1][j][k1][k2] %= mod;
                if (!dp1[i & 1][j][k1][k2]) continue;
                rep(k3, 2) dp1[(i + 1) & 1][j + (k3 == 0)][k2][k3] += (num[k3] - (k1 == k3)) * dp1[i & 1][j][k1][k2];
            }
        }
    }
    {
        int num[] = {1, 1, 24};
        rep(k1, 3) rep(k2, 3) {
            dp2[0][(k1 == 0) + (k2 == 0)][(k1 == 1) + (k2 == 1)][k1][k2] += num[k1] * num[k2];
        }
        REP(i, 2, n) {
            rep(j1, n + 1) rep(j2, n + 1) rep(k1, 3) rep(k2, 3) {
                dp2[(i + 1) & 1][j1][j2][k1][k2] = 0;
            }
            rep(j1, n + 1) rep(j2, n + 1) rep(k1, 3) rep(k2, 3) {
                dp2[i & 1][j1][j2][k1][k2] %= mod;
                if (!dp2[i & 1][j1][j2][k1][k2]) continue;
                rep(k3, 3) dp2[(i + 1) & 1][j1 + (k3 == 0)][j2 + (k3 == 1)][k2][k3] += (num[k3] - (k1 == k3)) * dp2[i & 1][j1][j2][k1][k2];
            }
        }
    }
    vector<int> cnt(26);
    rep(i, 26) cin >> cnt[i];
    ll ans = dp[n & 1];
    rep(i, 26) {
        REP(j, cnt[i] + 1, n + 1)
        rep(k, 2) rep(l, 2) ans += mod - dp1[n & 1][j][k][l] % mod;
        ans %= mod;
    };
    rep(i1, 26) rep(i2, i1) {
        REP(j1, cnt[i1] + 1, n + 1)
        REP(j2, cnt[i2] + 1, n + 1) rep(k, 3) rep(l, 3) ans += dp2[n & 1][j1][j2][k][l] % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}