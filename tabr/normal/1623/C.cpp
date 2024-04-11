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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long lo = 1;
        long long hi = (long long) 1e9 + 10;
        while (hi - lo > 1) {
            long long mid = (hi + lo) / 2;
            auto b = a;
            for (int i = n - 1; i >= 2; i--) {
                if (b[i] < mid) {
                    b[0] = 0;
                    break;
                }
                long long d = min(a[i], b[i] - mid) / 3;
                b[i - 1] += d;
                b[i - 2] += 2 * d;
                b[i] -= 3 * d;
            }
            if (b[0] >= mid && b[1] >= mid) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        cout << lo << '\n';
    }
    return 0;
}