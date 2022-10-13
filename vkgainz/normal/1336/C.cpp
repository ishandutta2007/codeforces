#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
typedef tree<
pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;
const int MX = 5e5 + 5;
ll mod = 998244353;
ll dp[3002][3002];
int main() {
  string s, t; cin >> s >> t;
  int n = s.length(), m = t.length();
  for(int j=1;j<=s.length();j++) {
    if(j<=t.length() && s[1-1]==t[j-1])
      dp[1][j] = 2;
    else if(j>t.length()) 
      dp[1][j] = 2;
  }
  for(int i=2;i<=s.length();i++) {
    for(int j=1;j<=s.length()-i+1;j++) {
      //[j, j+i-1]
      //add to front
      if(j<=t.length() && s[i-1]==t[j-1]) {
        dp[i][j]+=dp[i-1][j+1];
      }
      else if(j>t.length()) {
        dp[i][j]+=dp[i-1][j+1];
      }
      //add to back
      if((j+i-1)<=t.length() && s[i-1] == t[j+i-1-1]) {
        dp[i][j]+=dp[i-1][j];
      }
      else if(j+i-1 > t.length()) {
        dp[i][j]+=dp[i-1][j];
      }
      dp[i][j] %= mod;
    }
  }
  ll ans = 0LL;
  for(int i=t.length();i<=s.length();i++) {
    ans+=dp[i][1];
    ans %= mod;
  }
  if(ans < 0) ans += mod;
  cout << ans << "\n";
}