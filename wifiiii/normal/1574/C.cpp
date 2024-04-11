#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    ll sum = 0;
    for(ll i : a) sum += i;
    int m;
    cin >> m;
    while(m--) {
        ll x, y;
        cin >> x >> y;
        int p = lower_bound(a.begin(), a.end(), x) - a.begin();
        ll res = 2e18;
        {
            ll ans = 0, cur = sum;
            if(p == n) ans += x - a.back(), cur -= a.back();
            else cur -= a[p];
            ans += max(0ll, y - cur);
            res = min(res, ans);
        }
        if(p > 0) {
            --p;
            ll ans = x - a[p], cur = sum;
            cur -= a[p];
            ans += max(0ll, y - cur);
            res = min(res, ans);
        }
        cout << res << '\n';
    }
}