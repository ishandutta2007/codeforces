#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

void solve() {
    int n; cin >> n;
    vector c(2*n, vector<int>(2*n));
    for (auto& v : c) for (int& x : v) cin >> x;

    ll ans = numeric_limits<ll>::max();

    for (int x : array { 0, n-1 })
    for (int y : array { 0, n-1 }) {
        ckmin<ll>(ans, c[n+x][y]);
        ckmin<ll>(ans, c[x][n+y]);
    }

    for (int x = n; x < 2*n; ++x)
    for (int y = n; y < 2*n; ++y) {
        ans += c[x][y];
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}