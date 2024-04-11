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
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        int ans = n;
        for (int i = 1; i < n; i++) {
            vector<int> c;
            for (int j = 1; j <= n; j++) {
                if (pref[j] % pref[i] == 0) {
                    c.emplace_back(j);
                }
            }
            if ((int) c.size() == pref[n] / pref[i] && pref[n] % pref[i] == 0) {
                int t = 0;
                int z = 0;
                for (int j : c) {
                    z = max(z, j - t);
                    t = j;
                }
                ans = min(ans, z);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}