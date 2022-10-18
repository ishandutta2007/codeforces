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
        long long h;
        cin >> n >> h;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        a.emplace_back((long long) 3e18);
        long long lo = 0;
        long long hi = h;
        while (hi - lo > 1) {
            long long mid = (hi + lo) / 2;
            long long t = 0;
            for (int i = 0; i < n; i++) {
                t += min(mid, a[i + 1] - a[i]);
            }
            if (t >= h) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        cout << hi << '\n';
    }
    return 0;
}