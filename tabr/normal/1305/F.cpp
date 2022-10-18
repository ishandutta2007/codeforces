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
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    set<ll> st;
    for (int i = 0; i < 100; i++) {
        ll xs = rng();
        xs %= n;
        if (xs < 0) {
            xs += n;
        }
        for (int di = -1; di <= 1; di++) {
            ll x = a[xs] + di;
            for (ll d = 2; d * d <= x; d++) {
                if (x % d == 0) {
                    st.emplace(d);
                    while (x % d == 0) {
                        x /= d;
                    }
                }
            }
            st.emplace(x);
        }
    }
    st.erase(1);
    st.emplace(2);
    st.emplace(3);
    for (ll d : st) {
        if (d < 2) continue;
        ll res = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] < d) {
                res += d - a[j];
            } else {
                ll t = a[j] % d;
                res += min(t, d - t);
            }
            if (res >= ans) break;
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
    return 0;
}