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
        if (k == 1) {
            cout << (n + 1) / 2 - 1 << '\n';
        } else {
            int ans = 0;
            for (int i = 1; i < n - 1; i++) {
                if (a[i] > a[i - 1] + a[i + 1]) {
                    ans++;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}