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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long s = accumulate(a.begin(), a.end(), 0LL);
        long long mn = a[0];
        long long mx = a[n - 1];
        if (mn * (n - 2) + s > 0) {
            cout << "INF" << '\n';
            continue;
        }
        if (mx * (n - 2) + s < 0) {
            cout << "INF" << '\n';
            continue;
        }
        long long ans = (long long) -9e18;
        vector<long long> cmn(n);
        vector<long long> cmx(n);
        for (int i = 0; i < n; i++) {
            cmn[i] = mn * a[i];
            cmx[i] = mx * a[i];
        }
        cmn[0] = 0;
        cmx[n - 1] = 0;
        vector<long long> pref_mn(n + 1);
        for (int i = 0; i < n; i++) {
            pref_mn[i + 1] = pref_mn[i] + cmn[i];
        }
        vector<long long> pref_mx(n + 1);
        for (int i = 0; i < n; i++) {
            pref_mx[i + 1] = pref_mx[i] + cmx[i];
        }
        for (int i = 1; i < n; i++) {
            long long z = s + mn * (n - i - 1) + mx * (i - 1);
            z *= -a[i];
            z += pref_mn[n] - pref_mn[i];
            z += pref_mx[i];
            z -= mn * mx;
            ans = max(ans, z);
        }
        cout << ans << '\n';
    }
    return 0;
}