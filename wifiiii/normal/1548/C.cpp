#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;
const int maxn = 3100005;
ll f[maxn],rf[maxn];
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
void init(int n) {
    f[0] = 1;
    for(int i=1;i<=n;++i) f[i]=f[i-1]*i%mod;
    rf[n] = fpow(f[n],mod-2);
    for(int i=n-1;i>=0;--i) rf[i]=rf[i+1]*(i+1)%mod;
}
ll comb(ll n,ll k){if(n<k||k<0)return 0;return f[n]*rf[k]%mod*rf[n-k]%mod;}
const int inv3 = fpow(3, mod-2);
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    init(3 * n + 10);
    // [x^k] (1+x)^3 + (1+x)^6 + ... + (1+x)^3n
    // = [x^k] (1+x)^3 * ((1+x)^3n - 1) / ((1+x)^3 - 1)
    // = [x^k] ((1+x)^{3n+3} - (1+x)^3) / (3x + 3x^2 + x^3)
    // = ans[k]
    // then 3ans[k-1] + 3ans[k-2] + ans[k-3] = [x^k] ((1+x)^{3n+3} - (1+x)^3) = C(3n+3, k) - C(3, k)
    // ans[k] = (C(3n+3, k+1) - C(3, k+1) - 3ans[k-1] - ans[k-2]) / 3
    // ans[0] = n, ans[1] = 3 * (1 + n) * n / 2
    vector<ll> ans(3 * n + 1);
    ans[0] = n, ans[1] = 1ll * 3 * (1 + n) * n / 2 % mod;
    for(int i = 2; i <= 3 * n; ++i) {
        ans[i] = (comb(3 * n + 3, i + 1) - comb(3, i + 1) - 3 * ans[i-1] - ans[i-2]) * inv3 % mod;
        if(ans[i] < 0) ans[i] += mod;
    }
    while(q--) {
        int k;
        cin >> k;
        cout << ans[k] << endl;
    }
}