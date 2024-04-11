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
        vector<int> a(n);
        vector<ll> z(3000);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            z[a[i]]++;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            z[a[i]]--;
            vector<ll> x(3000), y = z;
            ll tmp = 0;
            for (int k = i + 1; k < n; k++) {
                tmp -= x[a[k]] * y[a[k]];
                y[a[k]]--;
                tmp += x[a[k]] * y[a[k]];
                if (a[i] == a[k]) {
                    ans += tmp;
                }
                tmp -= x[a[k]] * y[a[k]];
                x[a[k]]++;
                tmp += x[a[k]] * y[a[k]];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}