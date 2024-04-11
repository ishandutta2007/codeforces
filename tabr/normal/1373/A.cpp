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
        long long a, b, c;
        cin >> a >> b >> c;
        if (a * b <= c) {
            cout << 1 << " " << -1 << '\n';
        } else if (a >= c) {
            cout << -1 << " " << b << '\n';
        } else {
            cout << 1 << " " << b << '\n';
        }
    }
    return 0;
}