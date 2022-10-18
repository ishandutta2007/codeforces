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
            cin >> a[i] >> b[i];
        }
        int lo = 0, hi = n + 1;
        while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (b[i] >= cnt && a[i] >= mid - cnt - 1) {
                    cnt++;
                }
                if (cnt == mid) {
                    break;
                }
            }
            if (cnt >= mid) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        cout << lo << '\n';
    }
    return 0;
}