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
        ll l, r;
        cin >> l >> r;
        if (l * 2 <= r) {
            cout << l << " " << l * 2 << '\n';
        } else {
            cout << -1 << " " << -1 << '\n';
        }
    }
    return 0;
}