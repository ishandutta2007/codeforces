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
        ll l, r, m;
        cin >> l >> r >> m;
        ll d = r - l;
        for (ll a = l; a <= r; a++) {
            ll x = m % a;
            if (x <= d && m >= a) {
                cout << a << " " << l + x << " " << l << '\n';
                break;
            }
            if (a - x <= d) {
                cout << a << " " << l << " " << l + a - x << '\n';
                break;
            }
        }
    }
    return 0;
}