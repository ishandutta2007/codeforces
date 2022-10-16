#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int& x : v) cin >> x;
    sort(v.begin(), v.end());

    ll ans = v.back(), s = 0;
    for (int i = 0; i < n; ++i) {
        ans -= (ll) i * v[i] - s;
        s += v[i];
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while (t--) solve();
}