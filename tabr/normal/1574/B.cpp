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
        int a, b, c, m;
        cin >> a >> b >> c >> m;
        int d = max({a, b, c});
        if (a - 1 + b - 1 + c - 1 < m) {
            cout << "NO" << '\n';
        } else if (d - 1 - (a + b + c - d) > m) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
    return 0;
}