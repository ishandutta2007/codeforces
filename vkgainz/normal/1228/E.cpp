#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using ll = long long;
const int MX = 2e5+5;
ll kpow[70000], minpow[70000];
ll fact[251], choose[251][251];
ll invfact[251];
ll mod = 1e9+7;
ll getpow(ll b, ll p) {
  if(p == 0) return 1LL;
  ll x = getpow(b, p/2);
  if(p%2) return (((x*x)%mod*b)%mod+mod)%mod;
  else return ((x*x)%mod+mod)%mod;
}
ll inv(ll x) {
  return getpow(x, mod - 2);
}
ll eval(int a, int &n, int &k) {
  //nCa*(k-1)^(na)*(k^(n-a)-(k-1)^(n-a))^n
  ll ans = choose[n][a];
  ans*=minpow[n*a];
  ans%=mod;
  ll x = (kpow[n-a]-minpow[n-a])%mod;
  ll p = 1LL;
  for(int i=1;i<=n;i++) p*=x, p%=mod;
  ans*=p;
  ans%=mod;
  return ans;
}
int main() {
  int n, k; cin >> n >> k;
  fact[0] = 1LL;
  invfact[0] = 1LL;
  for(int i=1;i<=n;i++) {
    fact[i] = fact[i-1]*1LL*i%mod;
    invfact[i] = inv(fact[i]);
  }
  for(int i=0;i<=n;i++) {
    for(int j=0;j<=n;j++) {
      if(j>i) choose[i][j] = 0LL;
      else {
        choose[i][j] = fact[i]*1LL*invfact[j]%mod*1LL*invfact[i-j]%mod;
      }
    }
  }
  kpow[0] = 1LL, minpow[0] = 1LL;
  for(int i=1;i<70000;i++) {
    kpow[i] = kpow[i-1]*1LL*k%mod;
    minpow[i] = minpow[i-1]*1LL*(k-1)%mod;
  }
  ll ans = 0LL;
  for(int i=0;i<=n;i++) {
    if(i%2==0) ans+=eval(i, n, k);
    else ans-=eval(i, n, k);
    ans%=mod;
  }
  if(ans<0) ans+=mod;
  cout << ans << "\n";
}