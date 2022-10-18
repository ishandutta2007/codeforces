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
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            mp[a]++;
        }
        vector<int> c;
        for (auto p : mp) {
            c.emplace_back(p.second);
        }
        int m = (int) c.size();
        vector<int> pref(m + 1);
        for (int i = 0; i < m; i++) {
            pref[i + 1] = pref[i] + c[i];
        }
        int ans = (int) 1e9;
        for (int x = 0; x < 19; x++) {
            for (int y = 0; y < 19; y++) {
                int xc = 1 << x;
                int yc = 1 << y;
                int id = (int) (upper_bound(pref.begin(), pref.end(), xc) - pref.begin() - 1);
                if (id == m - 1) {
                }
                int t = xc - pref[id];
                int jd = (int) (upper_bound(pref.begin(), pref.end(), pref[id] + yc) - pref.begin() - 1);
                t += pref[id] + yc - pref[jd];
                int s = pref[m] - pref[jd];
                int u = 1;
                while (u < s) {
                    u <<= 1;
                }
                t += u - s;
                ans = min(ans, t);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}