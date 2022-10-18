#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        ll n, m;
        cin >> n >> m;
        ll lo = m, hi = m;
        vector<ll> t(n + 1), l(n + 1), h(n + 1);
        rep(i, 1, n + 1) cin >> t[i] >> l[i] >> h[i];
        rep(i, 0, n) {
            ll dift = t[i + 1] - t[i];
            lo -= dift, hi += dift;
            hi = min(hi, h[i + 1]);
            lo = max(lo, l[i + 1]);
            if (lo > hi) break;
        }
        if (lo <= hi)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}