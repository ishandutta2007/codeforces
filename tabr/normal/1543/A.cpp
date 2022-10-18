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
        long long a, b;
        cin >> a >> b;
        long long c = abs(a - b);
        if (c == 0) {
            cout << 0 << " " << 0 << '\n';
        } else {
            cout << c << " " << min(a % c, (c - a % c) % c) << '\n';
        }
    }
    return 0;
}