#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

constexpr int MAX_N = 128;

ll hei[MAX_N][MAX_N];
ll dp[MAX_N][MAX_N];

void solve() {
    int n, m; cin >> n >> m;

    rep(i, 0, n) rep(j, 0, m) {
        cin >> hei[i][j];
        hei[i][j] -= i+j;
    }

    ll ans = INT64_MAX;

    rep(xi, 0, n) rep(xj, 0, m) {
        ll wanted = hei[xi][xj];
        rep(i, 0, n) rep(j, 0, m) {
            if (hei[i][j] < wanted) {
                dp[i][j] = 1e18;
                continue;
            }
            if (i > 0 || j > 0) {
                dp[i][j] = INT64_MAX;
                if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j]);
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1]);
            } else {
                dp[i][j] = 0;
            }
            dp[i][j] += hei[i][j]-wanted;
        }
        ans = min(ans, dp[n-1][m-1]);
    }

    cout << ans << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}