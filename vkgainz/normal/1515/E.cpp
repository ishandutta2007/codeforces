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
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 3e5 + 5;
#define MAXN 200005
#define MAXE 400010
#define  INF (1<<29)
ll dp[401][401][2][2];
ll ans[401][401];
ll g[401];
ll fact[401], invfact[401];
ll M;
ll inv(int b, int p) {
  if(p==0) return 1LL;
  ll x = inv(b, p/2);
  x = x*x%M;
  if(p%2) x = x*b%M;
  return x;
}
ll choose(int a, int b) {
  if(b>a) return 0LL;
  return fact[a]*1LL*invfact[b]%M*1LL*invfact[a-b]%M;
}
int main() {
  int n; cin >> n >> M;
  fact[0] = 1LL;
  for(int i=1;i<=400;i++) {
    fact[i] = fact[i-1]*1LL*i%M;
  }
  invfact[400] = inv(fact[400], M-2);
  for(int i=399;i>=0;i--) {
    invfact[i] = invfact[i+1]*1LL*(i+1)%M;
  }
  for(int len=0;len<=n;len++) {
    if(len == 0) {
      g[len] = 1LL;
      continue;
    }
    for(int put=len;put>=1;put--) {
      g[len] += choose(len-1, put-1);
      g[len] %= M;
    }
  }
  for(int len=0;len<=n;len++) {
    for(int cover=0;cover<=n;cover++) {
      if(len == 0) {
        if(cover == 0) ++ans[len][cover];
        continue;
      }
      if(len == 1) {
        if(cover == 1) ++ans[len][cover];
        continue;
      }
      for(int gap=len-1;gap>=2;gap--) {
        if(cover-(len-gap)<0) continue;
        ans[len][cover] += g[len-gap]*1LL*ans[gap-1][cover-(len-gap)]%M*1LL*choose(cover, len-gap)%M;
        ans[len][cover] %= M;
      }
      if(cover == len)
        ans[len][cover] += g[len];
      ans[len][cover] %= M;
    }
  }
  ll ret = 0LL;
  for(int i=0;i<=n;i++) ret += ans[n][i], ret%=M;
  if(ret<0) ret +=M;
  cout << ret << "\n";
}