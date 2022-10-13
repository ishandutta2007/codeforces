#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;
ll fact[MX];
ll invfact[MX];
ll mod = 998244353;
ll getpow(ll x, ll p) {
  if(p==0) return 1LL;
  ll a = getpow(x, p/2);
  a= a*a%mod;
  if(p%2) a = a*x%mod;
  return a;
}
ll inv(ll x) {
  return getpow(x, mod- 2);
}
ll eval(int diff, int x) {
  if(diff-2*x<0) return 0LL;
  ll a = fact[diff];
  ll b = invfact[x];
  ll c = b;
  ll d= invfact[diff-2*x];
  return a*b%mod*c%mod*d%mod;
}
int main() {
  int n, k; cin >> n >> k;
  fact[0] = 1LL;
  invfact[0] = 1LL;
  for(int i=1;i<=n;i++) {
    fact[i] = fact[i-1]*1LL*i % mod;
    invfact[i] = inv(fact[i]);
  }
  vector<int> h(n);
  for(auto &a : h) cin >> a;
  int diff = 0;
  for(int i=0;i<h.size();i++) {
    if(h[i] != h[(i+1)%h.size()]) ++diff;
  }
  int same = n - diff;
  ll mult = getpow(k, same);
  ll ans = 0LL;
  for(int x=0;x<=diff/2;x++) {
    ans += eval(diff, x)*1LL*getpow(k-2, diff-2*x)%mod;
    ans%=mod;
  }
  ans = ans*mult%mod;
  ll tot = getpow(k, n)%mod;
  ll ret = (tot-ans)%mod*inv(2)%mod;
  if(ret<0) ret+=mod;
  cout << ret;
}