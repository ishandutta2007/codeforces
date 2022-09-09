#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, a, b; cin >> n >> a >> b;
    map<ll,ll> m;
    m[0] = 1; n--;
    if (min(a, b) == 0) {
        cout << n * (a + b) << endl;
        return 0;
    }
    while (n) {
        auto x = *m.begin();
        ll f = x.first, s = x.second;
        if (s <= n) {
            m[f + a] += s;
            m[f + b] += s;
            m.erase(m.begin());
            n -= s;
        }
        else {
            m[f + a] += n;
            m[f + b] += n;
            m[f] -= n; n = 0;
        }
    }
    ll r = 0;
    for (auto x : m) {
        ll f = x.first;
        ll s = x.second;
        r += f * s;
    }
    cout << r << endl;
    return 0;
}