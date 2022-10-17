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
        int n, k;
        cin >> n >> k;
        if(k == 0) {
            cout << 1 << endl;
        } else if(n % 2 == 0) {
            ll ans = 0, p = fpow(2, n - 1), cur = 1;
            for(int i = 0; i < k; ++i) {
                ans += fpow(2, 1ll * (k - 1 - i) * n) * cur % mod;
                cur = cur * (p - 1) % mod;
            }
            cout << (ans + cur) % mod << endl;
        } else {
            ll ans = fpow(fpow(2, n - 1) + 1, k);
            cout << ans << endl;
        }
    }
}