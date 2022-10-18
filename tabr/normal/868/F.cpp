#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 1e18));
    dp[0][0] = 0;
    vector<ll> c(n);
    ll L = 1, R = 1, cost = 0;
    c[a[1]] = 1;
    auto get = [&](ll l, ll r) {
        while (R < r) {
            R++;
            c[a[R]]++;
            cost += c[a[R]] - 1;
        }
        while (l < L) {
            L--;
            c[a[L]]++;
            cost += c[a[L]] - 1;
        }
        while (r < R) {
            cost -= c[a[R]] - 1;
            c[a[R]]--;
            R--;
        }
        while (L < l) {
            cost -= c[a[L]] - 1;
            c[a[L]]--;
            L++;
        }
        return cost;
    };
    function<void(int, int, int, int, int)> calc = [&](int j, int lo, int hi, int x, int y) {
        if (lo > hi) {
            return;
        }
        int mid = (hi + lo) / 2;
        int t = -1;
        ll cost = 0;
        for (int i = x; i <= min(mid - 1, y); i++) {
            if (dp[mid][j] > dp[i][j - 1] + get(i + 1, mid)) {
                t = i;
                dp[mid][j] = dp[i][j - 1] + get(i + 1, mid);
            }
        }
        assert(t != -1);
        calc(j, lo, mid - 1, x, t);
        calc(j, mid + 1, hi, t, y);
    };
    for (int j = 1; j <= k; j++) {
        calc(j, j, n, 0, n);
    }
    debug(dp);
    cout << dp[n][k] << '\n';
    return 0;
}