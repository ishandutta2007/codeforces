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
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, x, m;
        cin >> n >> x >> m;
        set<pair<ll, ll>> st;
        st.emplace(x, x);
        for (int i = 0; i < m; i++) {
            ll l, r;
            cin >> l >> r;
            bool ok = false;
            for (auto p : st) {
                if ((l <= p.first && p.first <= r) || (l <= p.second && p.second <= r)) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                st.emplace(l, r);
            }
        }
        if (st.empty()) {
            cout << 1 << '\n';
        } else {
            ll ans = 0;
            while (true) {
                pair<ll, ll> s(-1, -1), t;
                for (auto p : st) {
                    for (auto q : st) {
                        if (p == q) {
                            continue;
                        }
                        if ((q.first <= p.first && p.first <= q.second) || (q.first <= p.second && p.second <= q.second)) {
                            s = p, t = q;
                            break;
                        }
                    }
                    if (s.first != -1) {
                        break;
                    }
                }
                if (s.first == -1) {
                    break;
                }
                st.erase(s);
                st.erase(t);
                st.emplace(min(s.first, t.first), max(s.second, t.second));
            }
            for (auto p : st) {
                ans += p.second - p.first + 1;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}