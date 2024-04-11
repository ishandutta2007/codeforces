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
        int n;
        cin >> n;
        long long x, y;
        cin >> x >> y;
        for (int i = 0; i < n; i++) {
            long long a;
            cin >> a;
            x ^= a;
        }
        if (x % 2 == y % 2) {
            cout << "Alice" << '\n';
        } else {
            cout << "Bob" << '\n';
        }
    }
    return 0;
}