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
    const int MAX = (int) 2e5 + 10;
    vector<vector<int>> d(MAX);
    for (int i = 1; i < MAX; i++) {
        for (int j = 2; i * j < MAX; j++) {
            d[i * j].emplace_back(i);
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int l, r;
        cin >> l >> r;
        long long ans = 1LL * (r - l + 1) * (r - l) * (r - l - 1) / 6;
        for (int k = l; k <= r; k++) {
            int t = (int) (d[k].end() - lower_bound(d[k].begin(), d[k].end(), l));
            ans -= 1LL * t * (t - 1) / 2;
            if (k % 6 == 0 && k / 2 >= l) {
                ans--;
            }
            if (k % 15 == 0 && 2 * k / 5 >= l) {
                ans--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}