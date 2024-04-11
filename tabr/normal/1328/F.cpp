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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.emplace_back(2e9);
    for (int i = 0; i < n; i++) {
        s[i] = a[i] + (i ? s[i - 1] : 0);
    }
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (a[i] == a[j + 1]) {
            j++;
        }
        ll l = i, r = n - 1 - j, need = k - j + i - 1;
        ll tmp = 1e18;
        if (l < need && r < need) {
            tmp = (a[i] - 1LL) * l - s[i - 1] + s[n - 1] - s[j] - (a[i] + 1LL) * r;
        }
        if (l >= need) {
            tmp = min(tmp, (a[i] - 1LL) * l - s[i - 1]);
        }
        if (r >= need) {
            tmp = min(tmp, s[n - 1] - s[j] - (a[i] + 1LL) * r);
        }
        tmp += need;
        if (need <= 0) {
            tmp = 0;
        }
        debug(a[i], tmp, l, r, need);
        ans = min(ans, tmp);
        i = j;
    }
    cout << ans << endl;
    return 0;
}