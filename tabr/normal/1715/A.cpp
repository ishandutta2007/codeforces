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
        if (x + y == 2) {
            cout << 0 << '\n';
        } else {
            cout << x + y + min(x, y) - 2 << '\n';
        }
    }
    return 0;
}