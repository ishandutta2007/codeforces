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
        int k;
        cin >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        vector<int> w(k);
        ll ans = 0;
        for (int i = 0; i < k; i++) {
            cin >> w[i];
            w[i]--;
            ans += a[i];
        }
        sort(w.begin(), w.end());
        int j = k - 1;
        for (int i = 0; i < k; i++) {
            if (w[i] == 0) {
                ans += a[i];
                continue;
            }
            j += w[i];
            ans += a[j];
        }
        cout << ans << '\n';
    }
    return 0;
}