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
        int m = n + 10;
        vector<vector<int>> who(2 * m);
        who[m].emplace_back(0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            if ((s[i] == '+') == (i % 2 == 0)) {
                pref[i + 1]++;
            } else {
                pref[i + 1]--;
            }
            who[pref[i + 1] + m].emplace_back(i + 1);
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int k = pref[r + 1] - pref[l];
            if (k == 0) {
                cout << 0 << '\n';
                continue;
            } else if (abs(k) % 2 == 0) {
                cout << 2 << '\n';
                cout << l + 1 << " ";
                l++;
            } else {
                cout << 1 << '\n';
            }
            k = abs(pref[r + 1] - pref[l]);
            int z = pref[l];
            if (pref[r + 1] > pref[l]) {
                z += k / 2 + 1;
            } else {
                z -= k / 2 + 1;
            }
            z += m;
            cout << *upper_bound(who[z].begin(), who[z].end(), l) << '\n';
        }
    }
    return 0;
}