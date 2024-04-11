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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            if ((s[i] == '+') == (i % 2 == 0)) {
                pref[i + 1]++;
            } else {
                pref[i + 1]--;
            }
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int k = pref[r + 1] - pref[l];
            if (l % 2 == 1) {
                k *= -1;
            }
            if (k == 0) {
                cout << 0 << '\n';
            } else if (abs(k) % 2 == 0) {
                cout << 2 << '\n';
            } else {
                cout << 1 << '\n';
            }
        }
    }
    return 0;
}