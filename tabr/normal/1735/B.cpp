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
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            ans += a[i] / (2 * a[0] - 1);
            a[i] %= 2 * a[0] - 1;
            if (a[i] == 0) {
                ans--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}