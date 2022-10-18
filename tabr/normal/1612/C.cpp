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
        int k;
        long long x;
        cin >> k >> x;
        int lo = 0, hi = 2 * k - 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            long long c = 0;
            if (mid <= k) {
                c += 1LL * mid * (mid + 1) / 2;
            } else {
                c += 1LL * k * (k + 1) / 2;
                c += 1LL * k * (k - 1) / 2;
                c -= 1LL * (2 * k - 1 - mid) * (2 * k - mid) / 2;
            }
            if (c >= x) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        cout << hi << '\n';
    }
    return 0;
}