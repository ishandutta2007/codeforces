#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 3e5 + 5;

//ans[i][k] = sum of ans[j][k-1]/tau(i) for j | i
//ans[i][1] = sigma(i) / tau(i)
//ans[i][2] = 1 / tau(i) * sum of sigma(j) / tau(j) 
//ans[p^x][y] = sum of ans[p^(
ll mod = 1e9 + 7;
ll inv(int b, ll p = mod - 2) {
  if(p == 0) return 1LL;
  ll x = inv(b, p/2);
  if(p%2) return (((x*x)%mod*b)%mod+mod)%mod;
  else return ((x*x)%mod+mod)%mod;
}
ll get(ll p, int k, int numIter) {
  ll ans[k + 1][numIter + 1];
  ll getInv[k + 2];
  getInv[1] = 1LL;
  for(int i=2;i<=k + 1;i++) {
    getInv[i] = inv(i);
  }
  ans[0][0] = 1LL;
  for(int i=1;i<=k;i++) {
    ans[i][0] = ans[i-1][0]*1LL*p;
    ans[i][0] %= mod;
  }
  for(int r=1;r<=numIter;r++) {
    for(int i=0;i<=k;i++) {
      ans[i][r] = 0LL;
      for(int j=0;j<=i;j++) {
        ans[i][r] += ans[j][r - 1];
        ans[i][r] %= mod;
      }
      ans[i][r]*=getInv[i+1];
      ans[i][r]%=mod;
    }
  }
  return ans[k][numIter];
}
int main() {
  ll n;
  int k;
  cin >> n >> k;
  ll ans = 1LL;
  for(int i=2;i<=sqrt(n);i++) {
    if(n%i == 0) {
      int p = 0;
      while(n%i == 0) {
        ++p;
        n /= i;
      }
      ans *= get(i, p, k);
      ans %=mod;
    }
  }
  if(n > 1) ans *= get(n, 1, k);
  ans %= mod;
  if(ans < 0) ans += mod;
  cout << ans << "\n";
}