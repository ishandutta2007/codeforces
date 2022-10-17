#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const int mod = 1e9+7;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        map<ll,ll> mp;
        mp[0] = 1;
        ll ans = 1, cur = a[0];
        for(int i=1;i<n;++i) {
            ll tmp = ans;
            ans = (2 * ans - mp[cur]) % mod;
            mp[cur] = tmp;
            cur += a[i];
        }
        if(ans < 0) ans += mod;
        cout << ans << endl;
    }
}