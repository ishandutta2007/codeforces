#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    ll m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1), f(15);
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    ll ans = 0;
    rep(i, 0, n + 1) {
        ll c = 0, sum = 0;
        rep(j, 0, min(i + 1, (int)m)) {
            sum += a[i - j];
            c = max(c, sum);
        }
        f[i % m] = max(f[i % m] + sum, c) - k;
        ans = max(ans, f[i % m]);
    }
    cout << ans << endl;
    return 0;
}