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
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a * d == b * c) {
            cout << 0 << '\n';
        } else if (a == 0 || c == 0 || (a * d) % (b * c) == 0 || (b * c) % (a * d) == 0) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    return 0;
}