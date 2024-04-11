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
        if (accumulate(a.begin(), a.end(), 0LL) != 0) {
            cout << "No" << '\n';
            continue;
        }
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        if (*min_element(pref.begin(), pref.end()) < 0) {
            cout << "No" << '\n';
            continue;
        }
        string ans = "Yes";
        bool found = false;
        for (int i = 1; i < n; i++) {
            if (pref[i] == 0) {
                found = true;
            } else if (found) {
                ans = "No";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}