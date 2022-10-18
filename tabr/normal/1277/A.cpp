#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll m = n, l = 0;
        while (m / 10 != 0) {
            m /= 10;
            l++;
        }
        ll ans = 9 * l;
        m = 1;
        while (l--) {
            m *= 10;
            m++;
        }
        rep(i, 1, 10) if (m * (ll)i <= n) ans++;
        cout << ans << endl;
    }
    return 0;
}