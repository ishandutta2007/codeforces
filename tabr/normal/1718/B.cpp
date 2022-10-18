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
    vector<long long> f(55);
    f[0] = f[1] = 1;
    for (int i = 2; i < 55; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    vector<long long> pref(56);
    for (int i = 0; i < 55; i++) {
        pref[i + 1] = pref[i] + f[i];
    }
    debug(pref);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<long long> c(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        if (n == 1) {
            if (c[0] == 1) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
            continue;
        }
        long long s = accumulate(c.begin(), c.end(), 0LL);
        if (!binary_search(pref.begin(), pref.end(), s)) {
            cout << "No" << '\n';
            continue;
        }
        int k = (int) (lower_bound(pref.begin(), pref.end(), s) - pref.begin());
        string ans = "Yes";
        sort(c.rbegin(), c.rend());
        for (int i = k - 1; i >= 0; i--) {
            debug(c);
            if (c[0] < f[i]) {
                ans = "No";
                break;
            }
            c[0] -= f[i];
            reverse(c.begin(), c.end());
            sort(c.rbegin() + 1, c.rend());
        }
        cout << ans << '\n';
    }
    return 0;
}