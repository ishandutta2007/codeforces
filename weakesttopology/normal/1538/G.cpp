#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        auto f = [&](ll n) {
            ll nx = x - n * a, ny = y - n * b;
            double m = min(1.0 * nx / b, 1.0 * ny / a);
            return n + m;
        };
        ll L = 0, R = min(x / a, y / b);
        while (L < R) {
            ll M = L + (R - L) / 2;
            f(M) < f(M + 1) ? L = M + 1 : R = M;
        }
        ll ans = (ll)floor(f(L));
        cout << ans << endl;
    }
    exit(0);
}