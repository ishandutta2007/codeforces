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
        ll n;
        cin >> n;
        if (n <= 3) {
            cout << 1 << '\n';
            cout << n - 2 << '\n';
            continue;
        }
        ll a = 1, b = 1;
        vector<ll> ans;
        while (n >= a * 8LL) {
            ans.emplace_back(a);
            a <<= 1;
            b += a;
        }
        ll need = n - b;
        ll lo = a, hi = a * 2 + 1;
        while (hi - lo > 1) {
            ll mid = (lo + hi) / 2;
            if (mid * 2 <= need && need <= mid * 3) {
                lo = mid;
                hi = mid + 1;
                break;
            }
            if (mid * 3 < need) {
                lo = mid;
            }
            if (need < mid * 2) {
                hi = mid;
            }
        }
        ll x = lo;
        ll y = need - lo;
        ans.emplace_back(x - a);
        ans.emplace_back(y - x);
        cout << ans.size() << '\n';
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}