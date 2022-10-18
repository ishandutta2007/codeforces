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
        long long x, y, k;
        cin >> x >> y >> k;
        long long ans = k;
        x--;
        ans += (k * (y + 1) + x - 2) / x;
        cout << ans << '\n';
    }
    return 0;
}