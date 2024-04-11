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
        long long x, n;
        cin >> x >> n;
        long long d = 0;
        for (long long i = n / 4 * 4 + 1; i <= n; i++) {
            if (i % 4 == 1) {
                d += i;
            } else {
                d -= i;
            }
        }
        if (x % 2) {
            x += d;
        } else {
            x -= d;
        }
        cout << x << '\n';
    }
    return 0;
}