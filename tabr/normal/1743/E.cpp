#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()

using ll = long long;

template<class T>
using vec = vector<T>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll p1, t1, p2, t2, h, s;
    cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
    const ll inf = 4e18;
    vec<ll> dp(h + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= h + 10; i++) {
        for (int j = 1; j <= h + 10; j++) {
            ll t = max(t1 * i, t2 * j);
            ll d = (p1 - s) * i + (p2 - s) * j + s;
            d = min(d, h);
            dp[d] = min(dp[d], t);
        }
    }
    rep(z, 10) {
        for (int i = h - 1; i >= 0; i--) {
            dp[i] = min(dp[i], dp[i + 1]);
        }
        for (int i = 1; i < h; i++) {
            for (int j = 0; j <= h - i; j++) {
                dp[i + j] = min(dp[i + j], dp[i] + dp[j]);
            }
        }
    }
    ll ans = dp[h];
    rep(i, h) {
        ll low = 0;
        ll high = 1e18;
        while (high - low > 1) {
            ll mid = (high + low) >> 1;
            double ee = (mid / t1) * 1.0 * (p1 - s) + (mid / t2) * 1.0 * (p2 - s);
            if (ee > 1e6) {
                high = mid;
                continue;
            }
            ll e = (mid / t1) * (p1 - s) + (mid / t2) * (p2 - s);
            if (e >= h - i) {
                high = mid;
            } else {
                low = mid;
            }
        }
        ans = min(ans, high + dp[i]);
    }
    cout << ans << endl;
    return 0;
}