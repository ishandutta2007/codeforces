#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 998244353;
ll inv(ll b, ll p=mod-2) {
    if(p==0) return 1;
    ll x = inv(b,p/2);
    if(p%2) return ((((x*x)%mod*b)%mod+mod)%mod);
    else return (((x*x)%mod+mod)%mod);
}
int main() {
    int n; cin >> n;
    int a[2*n];
    for(int i=0;i<2*n;i++) cin >> a[i];
    sort(a,a+2*n);
    ll ans = 1;
    ll mult = 0;
    for(int i=0;i<2*n;i++) {
        if(i<n) mult-=a[i];
        else mult+=a[i];
    }
    mult%=mod;
    for(int i=1;i<=2*n-1;i++) ans = ans*1LL*i%mod;
    ll fact = 1;
    for(int i=1;i<=n-1;i++) fact = fact*1LL*i%mod;
    ans*=inv(fact);
    ans%=mod;
    fact = fact*1LL*n%mod;
    ans*=inv(fact);
    ans%=mod;
    ans*=mult;
    ans%=mod;
    ans*=2;
    ans%=mod;
    if(ans<0) ans+=mod;
    cout << ans << endl;
}