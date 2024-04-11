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
        long long k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int b = a[i + 1] - a[i];
            long long c = 1;
            for (int j = 0; j < b; j++) {
                c *= 10;
            }
            c--;
            if (c <= k) {
                k -= c;
                for (int j = 0; j < a[i]; j++) {
                    c *= 10;
                }
                ans += c;
            } else {
                c = k + 1;
                for (int j = 0; j < a[i]; j++) {
                    c *= 10;
                }
                ans += c;
                k = -1;
                break;
            }
        }
        long long c = k + 1;
        for (int j = 0; j < a[n - 1]; j++) {
            c *= 10;
        }
        ans += c;
        cout << ans << '\n';
    }
    return 0;
}