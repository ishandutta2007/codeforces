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
        int n, m;
        cin >> n >> m;
        int a = 0, b = 0;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            a = max(a, x);
            b = max(b, y);
        }
        if (a + b > n) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            while (a + b < n) {
                a++;
            }
            cout << string(a, 'R') + string(b, 'W') << '\n';
        }
    }
    return 0;
}