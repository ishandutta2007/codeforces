#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <random>

#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())
#define eb emplace_back
#define all(x) begin(x), end(x)

using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> c(n);
    for (int& x : c) cin >> x;
    vector<int> p { c[0], c[1] };
    ll s = c[0];
    ll ans = (ll)n*(c[0] + c[1]);
    for (int i = 1; i < n; ++i) {
        p[i%2] = min(p[i%2], c[i]);
        s += c[i];

        ll k0 = n - i / 2 - 1;
        ll k1 = n - (i + 1) / 2;

        ll cur = k0 * p[0] + k1 * p[1] + s;
        ans = min(ans, cur);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}