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
        string s;
        cin >> s;
        int n = (int) s.size();
        vector<vector<int>> pref(2, vector<int>(n + 1));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                pref[i][j + 1] = pref[i][j] + (s[j] - '0' == i);
            }
        }
        int low = -1;
        int high = n;
        while (high - low > 1) {
            int mid = (high + low) >> 1;
            bool ok = false;
            for (int i = 0; i < n; i++) {
                auto iter = upper_bound(pref[0].begin(), pref[0].end(), pref[0][i] + mid);
                int cnt1 = pref[1][i];
                if (iter != pref[0].end()) {
                    cnt1 += pref[1][n] - pref[1][iter - pref[0].begin()];
                }
                if (cnt1 <= mid) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << high << '\n';
    }
    return 0;
}