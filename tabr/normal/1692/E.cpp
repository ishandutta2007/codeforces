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
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (accumulate(a.begin(), a.end(), 0) < s) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        int ans = n;
        for (int i = 0, j = 0; i < n; i++) {
            while (j <= n && pref[j] - pref[i] <= s) {
                j++;
            }
            ans = min(ans, n + 1 - (j - i));
        }
        cout << ans << '\n';
    }
    return 0;
}