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
        string s;
        cin >> s;
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (s[i] == 'W');
        }
        int ans = n + 1;
        for (int i = 0; i <= n - k; i++) {
            ans = min(ans, pref[i + k] - pref[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}