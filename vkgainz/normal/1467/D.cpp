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

ll dp[5000+2][5000+1];
ll mod = 1e9+7;
int main() {
  int n, k, q; cin >> n >> k >> q;
  int a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=1;i<=n;i++) {
    dp[i][0] = 1;
  }
  for(int s=1;s<=k;s++) {
    for(int i=1;i<=n;i++) {
      dp[i][s] = dp[i-1][s-1]+dp[i+1][s-1];
      dp[i][s]%=mod;
    }
  }
  ll ans = 0LL;
  ll num[n];
  memset(num,0LL,sizeof(num));
  for(int i=1;i<=n;i++) {
    for(int s=0;s<=k;s++) {
      num[i-1]+=dp[i][s]*1LL*dp[i][k-s]%mod;
      num[i-1]%=mod;
    }
  }
  for(int i=0;i<n;i++) {
    ans+=num[i]*1LL*a[i]%mod;
    ans%=mod;
  }
  while(q--) {
    int i, x; cin >> i >> x;
    --i;
    int ch = x - a[i];
    a[i] = x;
    ans+=num[i]*1LL*ch%mod;
    ans%=mod;
    if(ans<0) ans+=mod;
    cout << ans << "\n";
  }
}