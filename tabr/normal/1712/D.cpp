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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int low = 0;
        int high = (int) 1e9 + 1;
        while (high - low > 1) {
            int mid = (high + low) >> 1;
            int cnt = 0;
            auto b = a;
            for (int i = 0; i < n; i++) {
                if (b[i] * 2 < mid) {
                    b[i] = (int) 1e9;
                    cnt++;
                }
            }
            int add = 2;
            for (int i = 0; i < n - 1; i++) {
                if (min(b[i], b[i + 1]) >= mid) {
                    add = 0;
                } else if (max(b[i], b[i + 1]) >= mid) {
                    add = min(add, 1);
                }
            }
            cnt += add;
            if (cnt <= k) {
                low = mid;
            } else {
                high = mid;
            }
        }
        cout << low << '\n';
    }
    return 0;
}