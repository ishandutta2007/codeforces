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
        int l, r;
        cin >> l >> r;
        int lo = 0;
        int hi = r;
        while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            if (max(l, mid + 1) + mid <= r) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        cout << lo << '\n';
    }
    return 0;
}