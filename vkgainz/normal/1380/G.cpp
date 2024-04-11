#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 3e5+5;
using cd = complex<double>;
const double PI = acos(-1);
ll ans[MX];
ll mod = 998244353;
ll inv(ll b, ll p = mod - 2) {
  if(p==0) return 1LL;
  ll x = inv(b, p/2);
  if(p%2) return (((x*x)%mod*b)%mod+mod)%mod;
  return ((x*x)%mod+mod)%mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<int> c(n);
  for(int i=0;i<n;i++) cin >> c[i];
  sort(c.begin(), c.end());
  vector<ll> pref(n);
  pref[0] = c[0];
  for(int i=1;i<n;i++) pref[i] = pref[i-1] + c[i];
  for(int k=1;k<=n;k++) {
    c.pop_back();
    pref.pop_back();
    ll temp = 0LL;
    int st = (int)pref.size() - 1, mult = 1;
    while(st>=0) {
      if(st - k < 0) temp+=mult*1LL*pref[st]%mod;
      else temp+=mult*1LL*(pref[st] - pref[st - k])%mod;
      st -= k, ++mult;
      temp%=mod;
    }
    ans[k-1] = temp;
  }
  ll x = inv(n);
  for(int i=0;i<n;i++) {
    cout << (ans[i]*1LL*x%mod+mod)%mod << "\n";
  }
}