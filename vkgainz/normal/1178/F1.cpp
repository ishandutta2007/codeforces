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
ll dp[502][502];
ll mod = 998244353;
int main() {
  int n, m; cin >> n >> m;
  vector<int> c(n);
  for(auto &a : c) cin >> a;
  for(int i=0;i<=501;i++)
    for(int j=0;j<=501;j++)
      dp[i][j] = 1LL;
  for(int len=1;len<=n;len++) {
    for(int i=1;i+len-1 <=n;i++) {
      int j = i+len-1;
      int mn = i;
      for(int x=i;x<=j;x++) {
        if(c[x-1] < c[mn-1]) mn = x;
      }
      ll x = 0LL, y = 0LL;
      for(int l=mn;l>=i;l--) {
        x += dp[l][mn-1]*1LL*dp[i][l-1];
        x %= mod;
      }
      for(int r=mn;r<=j;r++) {
        y += dp[mn+1][r]*1LL*dp[r+1][j];
        y %= mod;
      }
      dp[i][j] = x*1LL*y % mod;
    }
  }
  cout << (dp[1][n] + mod) % mod << "\n";
}