#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> vis(30);
        for(int i = 0; i < m; ++i) {
            int l, r, x;
            cin >> l >> r >> x;
            for(int j = 0; j < 30; ++j) {
                if(x >> j & 1) vis[j] = 1;
            }
        }
        ll ans = 0;
        for(int i = 0; i < 30; ++i) {
            if(vis[i]) ans += 1 << i;
        }
        ans = ans * fpow(2, n - 1) % mod;
        cout << ans << '\n';
    }
}