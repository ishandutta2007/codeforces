#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll sum = accumulate(a.begin(), a.end(), 0ll);
        ll m = n; int x = 2;
        if(n % 2 == 0) m /= 2, x /= 2;
        if(sum % m) {
            cout << 0 << '\n';
            continue;
        }
        ll res = sum / m * (m - x);
        ll p = sum - res;
        map<ll, int> mp;
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += mp[p - a[i]];
            mp[a[i]] += 1;
        }
        cout << ans << '\n';
    }
}