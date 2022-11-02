#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 300009;
const ll mod = 998244353;
const ll mod2 = 1e6;
ll mul(ll x,ll y){
    x%=mod,y%=mod;x=(x+mod)%mod,y=(y+mod)%mod;ll p=y/mod2;
    ll ans=(y%mod2*x%mod+(p*x)%mod*mod2%mod)%mod;
    ans=(ans+mod)%mod;
    return ans;
}
ll n,a[N];
ll fac[N],inv[N];
ll C(int x,int y){return mul(mul(fac[y],inv[x]),inv[y-x]);}
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=2*n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+2*n+1);
    for(int i=1;i<=2*n;i++) a[i]%=mod;
    fac[0]=1;
    for(int i=1;i<=2*n;i++) fac[i]=mul(fac[i-1],i);
    inv[0]=inv[1]=1;
    for(int i=2;i<=2*n;i++) inv[i]=mul(inv[mod%i],(mod-mod/i));
    for(int i=1;i<=2*n;i++) inv[i]=mul(inv[i],inv[i-1]);
    ll ans=0,val=C(n-1,2*n-1);   
    for(int i=1;i<n;i++){
        ans=(ans+mul(-a[i],val))%mod;
    }    
    ans=(ans-mul(a[n],val));
    ans=(ans%mod+mod)%mod;
    for(int i=n+1;i<=2*n;i++){
        ans=(ans+mul(a[i],val))%mod;
    }
    printf("%lld\n",ans*2ll%mod);
    return 0;
}