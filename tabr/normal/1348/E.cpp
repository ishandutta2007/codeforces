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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    ll s = 0, t = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        s += a[i];
        t += b[i];
    }
    ll ans = s / k + t / k;
    ll p = s % k, q = t % k;
    vector<bool> ok(k);
    ok[0] = true;
    for (int i = 0; i < n; i++) {
        vector<bool> new_ok = ok;
        for (int j = 0; j <= k; j++) {
            if (a[i] >= j && b[i] >= k - j) {
                for (int l = 0; l <= k; l++) {
                    if (ok[l]) {
                        new_ok[(l + j) % k] = true;
                    }
                }
            }
        }
        swap(ok, new_ok);
    }
    for (int i = 1; i < k; i++) {
        int j = k - i;
        if (p >= i && q >= j && ok[i]) {
            ans++;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}