#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 3e5+5;
int freq[MX], cnt[MX];
ll fact[MX], invfact[MX];
ll mod = 2038182301;
ll choose(int a, int b) {
  if(b > a) return 0LL;
  return fact[a]*1LL*invfact[b]%mod*invfact[a-b]%mod;
}
ll getpow(ll b, ll p) {
  if(p == 0) return 1LL;
  ll x = getpow(b, p/2);
  if(p%2) return (((x*x)%mod*b)%mod+mod)%mod;
  else return ((x*x)%mod+mod)%mod;
}
ll inv(ll x) {
  return getpow(x, mod - 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  for(int i=0;i<n;i++) {
    int x; cin >> x;
    ++freq[x];
  }
  for(int i=1;i<MX;i++) {
    for(int j=2*i;j<MX;j+=i) {
      freq[i]+=freq[j];
    }
  }
  cnt[1] = 1;
  for(int i=1;i<MX;i++) {
    for(int j=2*i;j<MX;j+=i) {
      cnt[j]-=cnt[i];
    }
  }
  fact[0] = 1LL;
  for(int i=1;i<MX;i++) fact[i] = fact[i-1]*1LL*i%mod;
  for(int i=0;i<MX;i++) invfact[i] = inv(fact[i]);
  int lo = 1, hi = n; //[lo, hi]
  for(int i=0;i<20;i++) {
    int mid = (lo+hi)/2;
    ll num = 0LL;
    for(int j=1;j<MX;j++) {
      num+=cnt[j]*1LL*choose(freq[j], mid)%mod;
      num%=mod;
    }
    if(num!=0) {
      hi = mid;
    }
    else {
      lo = mid+1;
    }
  }
  if(lo>n) cout << -1 << "\n";
  else cout << lo << "\n";
}