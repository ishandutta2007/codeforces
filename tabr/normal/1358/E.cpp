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
    int m = (n + 1) / 2;
    vector<ll> a(m);
    ll s = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        s += a[i];
    }
    ll x;
    cin >> x;
    s += x * (n - m);
    ll mn = 0, all = 0;
    for (int i = n; i >= m; i--) {
        if (s + mn > 0) {
            cout << i << '\n';
            return 0;
        }
        s -= x;
        all += x - a[n - i];
        mn = min(mn, all);
    }
    cout << -1 << '\n';
    return 0;
}