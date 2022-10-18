#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        ll s, t;
        cin >> n >> s;
        t = s;
        vector<pair<ll, ll>> lr(n);
        vector<ll> rx(n), lx(n);
        rep(i, 0, n) {
            cin >> lr[i].first >> lr[i].second;
            lx[i] = lr[i].first;
            rx[i] = lr[i].second;
            t -= lr[i].first;
        }
        sort(rx.begin(), rx.end());
        sort(lx.begin(), lx.end());
        ll r = rx[n / 2] + 1;
        ll l = lx[n / 2];
        while (r - l > 1) {
            ll m = (r + l) / 2LL;
            priority_queue<ll, vector<ll>, greater<ll>> q;
            rep(i, 0, n) {
                if (lr[i].second >= m)
                    q.push(max(0LL, m - lr[i].first));
            }
            if (q.size() < n / 2) {
                r = m;
                continue;
            }
            ll u = 0;
            rep(i, 0, n / 2 + 1) {
                u += q.top();
                q.pop();
            }
            if (u <= t) {
                l = m;
                continue;
            } else {
                r = m;
                continue;
            }
        }
        cout << l << endl;
    }
}