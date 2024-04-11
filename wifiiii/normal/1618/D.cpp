#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        ll ans = 0;
        for(int i = 0; i < n - 2 * k; ++i) ans += a[i];
        map<int, int> mp;
        for(int i = n - 2 * k; i < n; ++i) {
            mp[a[i]] += 1;
        }
        int mx = 0;
        for(auto [x, y] : mp) mx = max(mx, y);
        ans += max(0, mx - k);
        cout << ans << '\n';
    }
}