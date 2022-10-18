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
        long long k;
        cin >> k;
        vector<long long> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = 1;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}