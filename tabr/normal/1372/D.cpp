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
    vector<ll> a(n), s(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = a[i] + (i == 0 ? 0 : s[i - 1]);
    }
    for (int i = 0; i < n; i++) {
        s[i + n] = a[i] + s[i + n - 1];
    }
    ll z = 0;
    for (int i = 0; i < n - 1; i += 2) {
        z += a[i];
    }
    ll ans = z;
    for (int i = 1; i < n; i++) {
        if (i > 1) {
            z += s[i - 2];
        }
        z = s[i + n - 3] - z;
        ans = min(ans, z);
    }
    ans = accumulate(a.begin(), a.end(), 0LL) - ans;
    cout << ans << '\n';
    return 0;
}