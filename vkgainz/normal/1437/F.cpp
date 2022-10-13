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
const int BLOCK_SZ = 707;
vector<vector<int>> adj;
ll dp[5001][5001];
int main() {
  int n; cin >> n;
  vector<int> a(n);
  for(auto &a : a) cin >> a;
  sort(a.begin(), a.end());
  if(a[n-2]*2 > a[n-1]) {
    cout << 0 << "\n";
    return 0;
  }
  ll mod = 998244353;
  dp[n-1][n-1] = 1LL;
  for(int i=n-1;i>=0;i--) {
    for(int j=i;j<n;j++) {
      if(j==i) {
        for(int x=j+1;x<n;x++) {
          if(a[i]*2 <= a[x])
            dp[i][j] += dp[i+1][x];
          dp[i][j] %= mod;
        }
      }
      else {
        if(a[i] * 2 <= a[j]) 
          dp[i][j] += (n-i-1)*1LL*dp[i+1][j] % mod;
        else
          dp[i][j] += (n-i-2)*1LL*dp[i+1][j] % mod;
        dp[i][j] %= mod;
      }
    }
  }
  ll ans = 0LL;
  for(int i=0;i<n;i++) {
    ans += dp[0][i] ;
    ans %= mod;
  }
  if(ans < 0) ans += mod;
  cout << ans << "\n";
}