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
        int x, y;
        cin >> x >> y;
        int z = x * x + y * y;
        if (z == 0) {
            cout << 0 << '\n';
        } else {
            bool ok = false;
            for (int k = 0; k < 100; k++) {
                if (z == k * k) {
                    ok = true;
                }
            }
            if (ok) {
                cout << 1 << '\n';
            } else {
                cout << 2 << '\n';
            }
        }
    }
    return 0;
}