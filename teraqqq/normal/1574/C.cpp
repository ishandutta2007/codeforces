#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<ll> a(n); for (ll& x : a) cin >> x;
    sort(a.begin(), a.end());
    ll s = 0;
    for (ll x : a) s += x;

    const ll LINF = 1e18 + 1e12;

    int m; cin >> m;
    while (m--) {
        ll x, y; cin >> x >> y;
        int i = lower_bound(a.begin(), a.end(), x) - a.begin();

        ll ans = LINF;
        if (i != n) {
            ckmin(ans, max<ll>(0, y - s + a[i]));
        }

        if (i != 0) {
            i--;
            ckmin(ans, max<ll>(0, y - s + a[i]) + max<ll>(0, x - a[i]));
        }

        cout << ans << '\n';
    }
}