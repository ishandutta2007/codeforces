#include <bits/stdc++.h>
using namespace std;
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
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b * c) {
            cout << -1 << '\n';
            continue;
        }
        if (c < d) {
            cout << a << '\n';
            continue;
        }
        if (a < b * (d - 1)) {
            cout << a << '\n';
            continue;
        }
        long long res = a;
        long long t = a / (b * d);
        auto f = [&](long long k) {
            return a * (k + 1) - k * (k + 1) / 2 * d * b;
        };
        res = max(res, f(t));
        cout << res << '\n';
    }
    return 0;
}