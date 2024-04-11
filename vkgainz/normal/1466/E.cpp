#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MX = 5e5+5;
using ll = long long;
ll mod = 1e9+7;
int main() {
  int t; cin >> t;

  while(t--) {
    int n; scanf("%d",&n);
    ll x[n];
    for(int i=0;i<n;i++)
      scanf("%lld",&x[i]);
    int num[60];
    memset(num,0,sizeof(num));
    for(int i=0;i<n;i++) {
      for(int bit=0;bit<60;bit++) {
        if(x[i]&(1LL<<bit)) ++num[bit];
      }
    }
    ll a[n], o[n];
    memset(a, 0LL, sizeof(a));
    memset(o, 0LL, sizeof(o));
    ll t[60];
    t[0] = 1LL;
    for(int i=1;i<60;i++)
      t[i] = t[i-1]*1LL*2%mod;
    for(int i=0;i<n;i++) {
      for(int bit=0;bit<60;bit++) {
        if(x[i]&(1LL<<bit)) {
          o[i]+=t[bit]*1LL*n%mod;
        }
        else {
          o[i]+=t[bit]*1LL*num[bit]%mod;
        }
      }
      o[i]%=mod;
    }
    for(int i=0;i<n;i++) {
      for(int bit=0;bit<60;bit++) {
        if(x[i]&(1LL<<bit)) {
          a[i]+=(1LL<<bit)%mod*1LL*num[bit]%mod;
        }
      }
      a[i]%=mod;
    }
    ll ans = 0LL;
    for(int i=0;i<n;i++) {
      ans+=o[i]*1LL*a[i]%mod;
      ans%=mod;
    }
    if(ans<0) ans+=mod;
    printf("%lld\n",ans);
  }
}