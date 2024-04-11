#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll mod = 998244353, ans = 0;
    vector<vector<ll>> a(n);
    vector<ll> b(1000010);
    vector<ll> k(n), inv(1000010);
    inv[1] = 1;
    for (int i = 2; i < 1000010; i++) {
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
    }
    rep(i, 0, n) {
        cin >> k[i];
        rep(j, 0, k[i]) {
            ll c;
            cin >> c;
            a[i].emplace_back(c);
            b[c]++;
        }
    }
    rep(i, 0, n) {
        rep(j, 0, k[i]) {
            ans = (ans + b[a[i][j]] * inv[k[i]]) % mod;
        }
    }
    cout << ans * inv[n] % mod * inv[n] % mod << endl;
    return 0;
}