#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, sx, sy;
    cin >> n >> sx >> sy;
    ll u = 0, l = 0, d = 0, r = 0;
    rep(i, 0, n) {
        ll x, y;
        cin >> x >> y;
        if (x > sx)
            r++;
        if (x < sx)
            l++;
        if (y > sy)
            u++;
        if (y < sy)
            d++;
    }
    ll mx = max({u, l, r, d});
    cout << mx << endl;
    if (u == mx) {
        cout << sx << ' ' << sy + 1 << endl;
    } else if (r == mx) {
        cout << sx + 1 << ' ' << sy << endl;
    } else if (l == mx) {
        cout << sx - 1 << ' ' << sy << endl;
    } else {
        cout << sx << ' ' << sy - 1 << endl;
    }

    return 0;
}