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
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        long long ans = (long long) 1e18;
        for (int i = 0; i < n; i++) {
            long long s = pref[i + 1] - pref[1];
            long long cnt = n - 1 - i;
            s = k - s;
            long long b = s / (cnt + 1);
            if (b * (cnt + 1) > s) {
                b--;
            }
            cnt += max(0LL, a[0] - b);
            ans = min(ans, cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}