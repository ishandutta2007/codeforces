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


int main() {
  int n; cin >> n;
  ll ans = 0LL;
  ll x = 1;
  ll mod = 998244353;
  for(int i=0;i<n;i++) {
    x*=1LL*(n-i);
    x%=mod;
    ans-=x;
  }
  ans+=x*1LL*(n+1)%mod;
  ans%=mod;
  if(ans<0) ans+=mod;
  cout << ans;
}