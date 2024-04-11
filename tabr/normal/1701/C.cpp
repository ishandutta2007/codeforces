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
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < m; i++) {
            b[a[i] - 1]++;
        }
        int low = 0;
        int high = 2 * (m + n - 1) / n + 10;
        while (high - low > 1) {
            int mid = (high + low) >> 1;
            int cnt = 0;
            int can = 0;
            for (int i = 0; i < n; i++) {
                if (b[i] <= mid) {
                    can += (mid - b[i]) / 2;
                } else {
                    cnt += b[i] - mid;
                }
            }
            if (cnt <= can) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << high << '\n';
    }
    return 0;
}