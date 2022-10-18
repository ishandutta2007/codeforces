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
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if ((l1 <= l2 && l2 <= r1) || (l1 <= r2 && r2 <= r1) || (l2 <= l1 && l1 <= r2) || (l2 <= r1 && r1 <= r2)) {
            cout << max(l1, l2) << '\n';
        } else {
            cout << l1 + l2 << '\n';
        }
    }
    return 0;
}