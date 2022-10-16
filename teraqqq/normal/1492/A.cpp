#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;

void solve() {
    ll p, a, b, c;
    cin >> p >> a >> b >> c;
    ll ans = numeric_limits<ll>::max();
    ans = min(ans, p % a == 0 ? 0 : a - p%a);
    ans = min(ans, p % b == 0 ? 0 : b - p%b);
    ans = min(ans, p % c == 0 ? 0 : c - p%c);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}