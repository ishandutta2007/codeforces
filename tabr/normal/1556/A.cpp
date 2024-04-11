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
        long long c, d;
        cin >> c >> d;
        if (c == 0 && d == 0) {
            cout << 0 << '\n';
        } else if (c == d) {
            cout << 1 << '\n';
        } else if (abs(c - d) % 2 == 0) {
            cout << 2 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}