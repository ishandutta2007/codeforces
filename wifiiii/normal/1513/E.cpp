#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 200005;
const int mod = 1e9+7;
ll f[maxn],rf[maxn];
ll fpow(ll a,ll b) {
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
void init(int n) {
    f[0] = 1;
    for(int i=1;i<=n;++i) f[i]=f[i-1]*i%mod;
    rf[n] = fpow(f[n],mod-2);
    for(int i=n-1;i>=0;--i) rf[i]=rf[i+1]*(i+1)%mod;
}
ll comb(ll n,ll k){if(n<k||k<0)return 0;return f[n]*rf[k]%mod*rf[n-k]%mod;}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    init(n);
    vector<int> a(n);
    ll s = 0;
    map<int, int> mp;
    for(int i = 0; i < n; ++i) cin >> a[i], s += a[i], mp[a[i]]++;
    ll inv = 1;
    for(auto p : mp) inv = inv * rf[p.second] % mod;
    if(s % n) {
        cout << 0 << endl;
        return 0;
    }
    int b = 0, e = 0, l = 0;
    s /= n;
    for(int i = 0; i < n; ++i) {
        if(a[i] == s) ++e;
        if(a[i] > s) ++b;
        if(a[i] < s) ++l;
    }
    if(b <= 1 || l <= 1) {
        cout << f[n] * inv % mod << endl;
        return 0;
    }
    ll ans = 2 * f[b] % mod * f[l] % mod * comb(n, e) % mod * f[e] % mod;
    cout << ans * inv % mod << endl;
}