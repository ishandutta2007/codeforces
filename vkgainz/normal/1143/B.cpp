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

int main() {
  int n; cin >> n;
  vector<array<ll, 2>> dp(11);
  vector<int> dig;
  while(n>0) {
    dig.push_back(n%10);
    n/=10;
  }
  reverse(dig.begin(), dig.end());
  dp[0][0] = dig[0];
  dp[0][1] = max(dig[0] -1, 1);
  for(int i=1;i<dig.size();i++) {
    int curr = dig[i];
    dp[i][0] = dp[i-1][0]*1LL*curr;
    for(int j=0;j<=9;j++) {
      dp[i][1] = max(dp[i][1], dp[i-1][1]*1LL*j);
      if(j<curr) dp[i][1] = max(dp[i][1], dp[i-1][0]*1LL*j);
    }
  }
  cout << max(dp[dig.size()-1][0], dp[dig.size()-1][1]);
}