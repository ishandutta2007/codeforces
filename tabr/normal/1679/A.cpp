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
        long long n;
        cin >> n;
        if (n % 2 == 1 || n == 2) {
            cout << -1 << '\n';
        } else {
            long long x, y;
            if (n % 6 == 0) {
                x = n / 6;
            } else if (n % 6 == 2) {
                x = (n - 8) / 6 + 2;
            } else {
                x = (n - 4) / 6 + 1;
            }
            if (n % 4 == 0) {
                y = n / 4;
            } else {
                y = (n - 6) / 4 + 1;
            }
            cout << x << " " << y << '\n';
        }
    }
    return 0;
}