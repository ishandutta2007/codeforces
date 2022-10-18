#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll ans = 0;
    if (e < f) {
        ll x = min({b, c, d});
        ans += x * f;
        d -= x;
        ans += min(a, d) * e;
        cout << ans << endl;
    } else {
        ll x = min(a, d);
        ans += x * e;
        d -= x;
        ans += min({b, c, d}) * f;
        cout << ans << endl;
    }

    return 0;
}