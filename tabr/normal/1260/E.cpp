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
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    int fr = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            fr = i;
        }
    }
    int m = 0;
    vector<int> v;
    while ((1 << (m + 1)) <= n) {
        m++;
        v.emplace_back(1 << m);
    }
    int need = 0;
    while ((1 << (need + 1)) <= fr) {
        need++;
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    need = m - need;
    reverse(v.begin(), v.end());
    debug(v, need);
    int id = 0;
    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        pq.push(a[i]);
        if (id < need && v[id] == i) {
            id++;
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}