#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        ll need = 0;
        ll add = 0;
        ll cap = 1e18;
        string ans = "YES";
        for (int i = n - 1; i >= 0; i--) {
            if (b[i] < need) {
                ans = "NO";
                break;
            }
            ll c = b[i] - a[i];
            if (c >= 0) {
                if (c > need) {
                    ll d = min(cap, c - need);
                    cap -= d;
                    add += d;
                    need = 0;
                } else {
                    need -= c;
                }
            }
            ll e = min(a[i], b[i]);
            if (need > e) {
                ans = "NO";
                break;
            }
            cap = min(cap, e - need);
            if (c < 0) {
                need -= c;
            }
            debug(cap, need);
        }
        if (need > add) {
            ans = "NO";
        }
        cout << ans << '\n';
    }
    return 0;
}