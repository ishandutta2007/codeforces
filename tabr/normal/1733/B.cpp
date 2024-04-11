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
        int n, x, y;
        cin >> n >> x >> y;
        if (x < y) {
            swap(x, y);
        }
        if (y != 0) {
            cout << -1 << '\n';
            continue;
        }
        if (x == 0 || (n - 1) % x != 0) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 0; i < n - 1; i++) {
            cout << i / x * x + 2 << " \n"[i == n - 2];
        }
    }
    return 0;
}