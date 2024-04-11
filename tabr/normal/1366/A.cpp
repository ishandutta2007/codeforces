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
        ll a, b;
        cin >> a >> b;
        ll ans = 0;
        while (a > 0 && b > 0) {
            if (a > b) {
                swap(a, b);
            }
            if (a == b) {
                ans += a / 3 * 2;
                a %= 3;
                if (a == 2) {
                    ans++;
                }
                break;
            }
            if (a * 2 < b) {
                ans += a;
                break;
            }
            ll c = b - a;
            ans += c;
            b -= c * 2;
            a -= c;
        }
        cout << ans << '\n';
    }
    return 0;
}