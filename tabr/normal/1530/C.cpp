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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        for (int i = 1; i < n; i++) {
            a[i] += a[i - 1];
            b[i] += b[i - 1];
        }
        int lo = -1, hi = 100 * n + 10;
        while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            int k = (n + mid) - (n + mid) / 4;
            int x = 100 * k;
            if (k > mid) {
                x = 100 * mid;
                x += a[min(n, k - mid) - 1];
            }
            int y = b[min(k, n) - 1];
            if (x >= y) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        cout << hi << '\n';
    }
    return 0;
}