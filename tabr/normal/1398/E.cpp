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
    set<ll> big, a, b, small;
    ll all = 0;
    for (int i = 0; i < n; i++) {
        ll tp, d;
        cin >> tp >> d;
        all += d;
        if (d > 0) {
            small.emplace(d);
            if (tp == 0) {
                a.emplace(d);
            } else {
                b.emplace(d);
            }
        } else {
            d *= -1;
            if (big.count(d)) {
                big.erase(d);
                all -= d;
            } else {
                small.erase(d);
            }
            if (tp == 0) {
                a.erase(d);
            } else {
                b.erase(d);
            }
        }
        while (b.size() < big.size()) {
            ll t = *big.begin();
            all -= t;
            small.emplace(t);
            big.erase(t);
        }
        while (b.size() > big.size()) {
            ll t = *small.rbegin();
            all += t;
            big.emplace(t);
            small.erase(t);
        }
        while (!big.empty() && !small.empty() && *big.begin() < *small.rbegin()) {
            ll s = *big.begin(), t = *small.rbegin();
            big.erase(s);
            small.erase(t);
            big.emplace(t);
            small.emplace(s);
            all += t - s;
        }
        ll res = all;
        if (!a.empty() && !b.empty()) {
            if (*a.rbegin() < *b.begin()) {
                res += *a.rbegin() - *b.begin();
            }
        } else if (a.empty() && !b.empty()) {
            res -= *b.begin();
        }
        cout << res << '\n';
    }
    return 0;
}