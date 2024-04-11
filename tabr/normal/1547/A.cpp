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
        int xa, ya, xb, yb, xc, yc;
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        if (xa == xb && xb == xc) {
            swap(xa, ya);
            swap(xb, yb);
            swap(xc, yc);
        }
        int ans = abs(xa - xb) + abs(ya - yb);
        if (ya == yb && yb == yc) {
            if (xa > xb) {
                swap(xa, xb);
            }
            if (xa < xc && xc < xb) {
                ans += 2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}