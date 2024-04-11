#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MX = 2e5+5;
using ll = long long;
ll fac[MX];
ll mod = 1e9+7;
ll inv(ll b, ll p = mod-2) {
  if(p==0) return 1LL;
  ll x = inv(b, p/2);
  if(p%2) return (((x*x)%mod*b)%mod+mod)%mod;
  else return ((x*x)%mod+mod)%mod;
}
ll choose(int a, int b) {
  if(a<b) return 0LL;
  ll x = fac[a];
  ll y = fac[b];
  ll z = fac[a-b];
  return (x*inv(y)%mod*inv(z)%mod+mod)%mod;
}
int main() {
  int t; cin >> t;
  fac[0] = 1LL;
  for(int i=1;i<MX;i++)
    fac[i] = fac[i-1]*1LL*i%mod;
  while(t--) {
    int n,m,k; cin >> n >> m >> k;
    int a[n];
    for(int i=0;i<n;i++)
      cin >> a[i];
    sort(a, a+n);
    if(m==1) {
      cout << n << "\n";
      continue;
    }
    int l = 0;
    ll ans = 0LL;
    for(int r=0;r<n;r++) {
      while(l<=r && a[r]-a[l]>k)
        ++l;
      ans+=choose(r-l, m-1);
      ans%=mod;
    }
    if(ans<0) ans+=mod;
    cout << ans << "\n";
  }
}