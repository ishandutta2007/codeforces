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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = abs(a - c) + abs(b - d);
        if (a != c && b != d) {
            ans += 2;
        }
        cout << ans << '\n';
    }
    return 0;
}