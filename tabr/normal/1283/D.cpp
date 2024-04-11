#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> x(n);
    rep(i, 0, n) {
        cin >> x[i];
    }
    x.emplace_back(-2e9);
    x.emplace_back(2e9);
    sort(x.begin(), x.end());

    ll l = 0, r = 100000;
    while (r - l > 1) {
        ll mid = (r + l) / 2;
        ll cnt = -2e9, sum = 0;
        rep(j, 1, n + 1) {
            if (sum >= m) break;
            for (ll i = max(cnt + 1, x[j] - mid); i <= x[j] + mid; i++) {
                cnt = i;
                if (i == x[j]) continue;
                if (i == x[j + 1]) break;
                sum++;
            }
        }
        if (sum < m)
            l = mid;
        else
            r = mid;
    }
    vector<ll> a, b;
    ll cnt = -2e9, sum = 0;
    rep(j, 1, n + 1) {
        for (ll i = max(cnt + 1, x[j] - r); i <= x[j] + r; i++) {
            if (i == x[j]) continue;
            auto it = lower_bound(x.begin(), x.end(), i);
            ll dif = min(*it - i, i - *(it - 1));
            if (dif == r)
                b.emplace_back(i);
            else if (dif != 0) {
                a.emplace_back(i);
                sum += dif;
            }
            cnt = i;
        }
    }
    cout << (m - a.size()) * r + sum << endl;
    rep(i, 0, a.size()) cout << a[i] << ' ';
    rep(i, 0, m - a.size()) cout << b[i] << ' ';
    cout << endl;

    return 0;
}