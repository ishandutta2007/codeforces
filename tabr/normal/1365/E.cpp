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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n < 4) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans |= a[i];
        }
        cout << ans << '\n';
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                ans = max(ans, a[i] | a[j] | a[k]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}