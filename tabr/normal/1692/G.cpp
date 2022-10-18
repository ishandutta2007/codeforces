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
        vector<int> pref(n);
        for (int i = 0; i < n - 1; i++) {
            pref[i + 1] = pref[i] + (a[i] < a[i + 1] * 2);
        }
        int ans = 0;
        for (int i = 0; i + k < n; i++) {
            if (pref[i + k] - pref[i] == k) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}