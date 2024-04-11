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
    vector<ll> v(1, 1);
    for (int i = 0; i < 31; i++) {
        v.emplace_back(v.back() + (1LL << (2 * i)));
    }
    vector<ll> bb = {0, 2, 3, 1};
    int tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        ll m = (n + 2) / 3;
        ll a, b, c;
        int i = upper_bound(v.begin(), v.end(), m) - v.begin() - 1;
        ll t = m - v[i];
        a = (1LL << (2 * i)) + t;
        b = 0;
        for (int i = 0;; i++) {
            ll msk = a;
            msk /= (1LL << (2 * i));
            if (msk == 0) break;
            msk %= 4;
            msk = bb[msk];
            msk <<= (2 * i);
            b += msk;
        }
        c = a ^ b;
        if (n % 3 == 1) {
            cout << a << '\n';
        } else if (n % 3 == 2) {
            cout << b << '\n';
        } else {
            cout << c << '\n';
        }
    }
    return 0;
}