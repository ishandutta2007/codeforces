#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MX = 1e6+5;
using ll = long long;
ll mod = 998244353;
ll getPow(ll b, ll p) {
  if(p==0)
    return 1LL;
  ll x = getPow(b, p/2);
  if(p%2) return (((x*x)%mod*b)%mod+mod)%mod;
  else return ((x*x)%mod+mod)%mod;
}
ll equiv(ll x, ll a) {
  //a^(2x)-((a^(2x))*(a^(2x)-1)/2)
  ll ans = getPow(a, 2*x)%mod;
  ll s = getPow(a, x)%mod;
  ll sub =  s*(s-1)/2%mod;
  return ((ans-sub)%mod+mod)%mod;
}
int main() {
  int n, m, a;
  cin >> n >> m >> a;
  int b[m];
  for(int i=0;i<m;i++)
    cin >> b[i];
  ll ans = getPow(a, n-2*b[m-1])%mod;
  ans*=equiv(b[0], a)%mod;
  ans%=mod;
  for(int i=1;i<m;i++) {
    ans*=equiv(b[i]-b[i-1], a)%mod;
    ans%=mod;
  }
  if(ans<0)ans+=mod;
  cout << ans << "\n";
}