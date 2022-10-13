#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 200+5;
ll mod = 998244353;
ll fac[5001]; //1*2*...
ll invfac[5001]; //(1*2*...)^-1
ll revfac[5001]; //n*(n-1)*...
ll kpow[5001]; //x^n
ll invmpow[5001]; //m^(-x)
ll fval[5001];
ll getpow(ll b, ll p) {
  if(p == 0) return 1LL;
  ll x = getpow(b, p/2);
  if(p%2) return (((x*x)%mod*b)%mod+mod)%mod;
  else return ((x*x)%mod+mod)%mod;
}
ll inv(ll x) {
  return getpow(x, mod - 2);
}
ll choose(int a, int b) {
  if(b > a) return 0LL;
  ll x = fac[a], y = invfac[b], z = invfac[a-b];
  return x*1LL*y%mod*1LL*z%mod;
}
ll bigchoose(int &n, int x) {
  ll a = revfac[x], b = invfac[x];
  return a*b%mod;
}
ll f(int x, int &k) {
  //x^n-xC1*(x-1)^n+xC2*(x-2)^n.
  ll ans = 0LL;
  for(int i=0;i<=x;i++) {
    ll a = kpow[x-i];
    ll b = choose(x, i);
    if(i%2==0) ans+=(a*b%mod);
    else ans-=(a*b%mod);
    ans%=mod;
  }
  return ans;
}
ll eval(int x, int &n, int &m, int &k) {
  //nCx * f(x, n)* 1/m^x
  ll ans = bigchoose(n, x)%mod*1LL*fval[x]%mod*1LL*invmpow[x]%mod; 
  return ans;
}
int main() {
  int n, m, k; cin >> n >> m >> k;
  fac[0] = 1LL;
  for(int i=1;i<=5000;i++) fac[i] = fac[i-1]*1LL*i%mod;
  for(int i=0;i<=5000;i++) invfac[i] = inv(fac[i]);
  revfac[0] = 1LL;
  for(int i=1;i<=5000;i++) revfac[i] = revfac[i-1]*1LL*(n-i+1)%mod;
  for(int i=0;i<=5000;i++) kpow[i] = getpow(i, k);
  ll x = inv(m);
  invmpow[0] = 1LL;
  for(int i=1;i<=5000;i++) invmpow[i] = invmpow[i-1]*1LL*x%mod;
  for(int i=0;i<=k;i++) fval[i] = f(i, k);
  ll ans = 0LL;
  for(int x=0;x<=k;x++) {
    //cout << x << " " << eval(x, n, m) << "\n";
    ans+=eval(x, n, m, k);
    ans%=mod;
  }
  cout << (ans+mod)%mod << "\n";
}