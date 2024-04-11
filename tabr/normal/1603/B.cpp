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
    /*
    for (int x = 2; x <= 12; x += 2) {
        for (int y = 2; y <= 30; y += 2) {
            if (y % x == 0) {
                continue;
            } else if (y > x) {
                int n = y - (y % x) / 2;
                assert(n % x == y % n);
                continue;
            }
            debug(x, y);
            for (int n = 1; n < x * y; n++) {
                if (n % x == y % n) {
                    debug(n, n % x);
                }
            }
        }
    }
    */
    int tt;
    cin >> tt;
    while (tt--) {
        long long x, y;
        cin >> x >> y;
        if (y % x == 0) {
            cout << x << '\n';
            continue;
        } else if (y > x) {
            long long b = (y % x) / 2;
            cout << y - b << '\n';
        } else {
            cout << x + y << '\n';
        }
    }
    return 0;
}