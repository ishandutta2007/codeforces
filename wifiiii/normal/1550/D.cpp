#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 200005;
const int mod = 1e9+7;
ll f[maxn],rf[maxn];
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
void init(int n) {
    f[0] = 1;
    for(int i=1;i<=n;++i) f[i]=f[i-1]*i%mod;
    rf[n] = fpow(f[n],mod-2);
    for(int i=n-1;i>=0;--i) rf[i]=rf[i+1]*(i+1)%mod;
}
ll comb(ll n,ll k){if(n<k||k<0)return 0;return f[n]*rf[k]%mod*rf[n-k]%mod;}
int main() {
    init(maxn - 1);
    int t;
    cin >> t;
    while(t--) {
        int n, l, r;
        cin >> n >> l >> r;
        ll ans = 0;
        for(int a = min(r - 1, n - l); a > 0; --a) {
            int L = min(n, r - a), R = min(n, n - a - l + 1);
            ll tmp = 0;
            if(n % 2 == 0) {
                int resl = n - R, resr = n - L;
                int cntl = n / 2, cntr = n / 2;
                tmp += comb(n - resl - resr, cntl - resl);
                if(L == n && R == n) {
                    ans += tmp * a % mod;
                    break;
                } else {
                    ans += tmp;
                }
            } else {
                int resl = n - R, resr = n - L;
                int cntl = n / 2, cntr = n / 2;
                tmp += comb(n - resl - resr, n / 2 - resl);
                tmp += comb(n - resl - resr, n / 2 - resr);
                if(L == n && R == n) {
                    ans += tmp * a % mod;
                    break;
                } else {
                    ans += tmp;
                }
            }
        }
        ans %= mod;
        cout << ans << endl;
    }
}