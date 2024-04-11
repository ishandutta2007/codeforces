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
        long long n;
        cin >> n;
        vector<long long> c;
        long long x = 1;
        x = 6;
        for (int i = 4; x <= n; i++) {
            c.emplace_back(x);
            x *= i;
        }
        int sz = (int) c.size();
        int ans = 1919191;
        for (int mask = 0; mask < (1 << sz); mask++) {
            x = n;
            for (int i = 0; i < sz; i++) {
                if (mask & (1 << i)) {
                    x -= c[i];
                }
            }
            if (x < 0) {
                continue;
            }
            ans = min(ans, __builtin_popcount(mask) + __builtin_popcountll(x));
        }
        cout << ans << '\n';
    }
    return 0;
}