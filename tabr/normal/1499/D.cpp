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
    const int MAX = 20000002;
    vector<int> f(MAX);
    for (int i = 2; i < MAX; i++) {
        if (f[i]) {
            continue;
        }
        for (int j = 1; i * j < MAX; j++) {
            f[i * j]++;
        }
    }
    while (tt--) {
        int c, d, x;
        cin >> c >> d >> x;
        long long ans = 0;
        for (int g = 1; g * g <= x; g++) {
            if (x % g != 0) {
                continue;
            }
            if (g != x / g && (g + d) % c == 0) {
                ans += 1LL << f[(g + d) / c];
            }
            if ((x / g + d) % c == 0) {
                ans += 1LL << f[(x / g + d) / c];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}