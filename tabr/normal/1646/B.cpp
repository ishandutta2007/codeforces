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
        sort(a.begin(), a.end());
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        string ans = "NO";
        for (int i = 1; 2 * i + 1 <= n; i++) {
            if (pref[i + 1] < pref[n] - pref[n - i]) {
                ans = "YES";
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}