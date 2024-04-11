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

const int C = 3e7+6;

int pd[C];

void solve() {
    ll c, d, x; cin >> c >> d >> x;
    vector<ll> v;
    for (ll d = 1; d*d <= x; ++d) {
        if (x % d == 0) {
            v.push_back(d);
            if (d*d < x) v.push_back(x/d);
        }
    }

    ll ans = 0;
    for (ll g : v) {
        ll k = x / g + d;
        if (k % c != 0) continue;
        k /= c;
        ans += 1LL << pd[k];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    for (int i = 2; i < C; ++i) {
        if (pd[i]) continue;
        for (int j = i; j < C; j += i)
            pd[j]++;
    }

    int t; cin >> t;
    while(t--) solve();
}