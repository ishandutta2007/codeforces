#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    auto dif = [&](ll a, ll x) {
        return a - x * (x - 1) * 3 - 1;
    };
    auto count = [&](ll a, ll m) {
        ll lo = 0, hi = a + 1;
        while (hi - lo > 1) {
            ll mid = (hi + lo) / 2;
            if (dif(a, mid) >= m) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    };
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll l = -4e18, r = 4e18;
    while (r - l > 1) {
        ll mid = l + (r - l) / 2;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += count(a[i], mid);
        }
        if (sum > k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        b[i] = count(a[i], r);
        sum += b[i];
    }
    ll c = k - sum;
    debug(c, l, r);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 0; i < n; i++) {
        ll d = b[i] * (b[i] + 1) * 3LL - a[i] + 1;
        pq.emplace(d, i);
    }
    while (c--) {
        ll d = pq.top().first;
        int id = pq.top().second;
        pq.pop();
        if (b[id] == a[id]) {
            c++;
            continue;
        }
        b[id]++;
        d = b[id] * (b[id] + 1) * 3LL - a[id] + 1;
        pq.emplace(d, id);
    }
    for (ll i : b) {
        cout << i << " ";
    }
    cout << '\n';
}