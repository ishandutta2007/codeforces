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
    int n;
    cin >> n;
    int low = 2 * n - 2;
    int high = 2000 * n + n - 1;
    while (high - low > 1) {
        int mid = (high + low) >> 1;
        cout << "? " << mid << endl;
        int t;
        cin >> t;
        if (t != 1) {
            low = mid;
        } else {
            high = mid;
        }
    }
    int ans = high;
    for (int h = 2; h <= n; h++) {
        int k = high / h;
        cout << "? " << k << endl;
        int t;
        cin >> t;
        if (t > 0) {
            ans = min(ans, t * k);
        }
    }
    cout << "! " << ans << endl;
    return 0;
}