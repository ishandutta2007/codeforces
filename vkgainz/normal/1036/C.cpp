#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
const int MX = 1e6+5;
ll get(ll x) {
  ll dp[21][4][2]; //eq or not eq
  for(int i=0;i<=20;i++) {
    for(int j=0;j<4;j++)
      dp[i][j][0] = 0, dp[i][j][1] = 0;
  }
  dp[0][0][0] = 1;
  vector<int> dig;
  while(x>0) {
    dig.push_back(x%10);
    x/=10;
  }
  //0 = eq
  reverse(dig.begin(), dig.end());
  for(int i=1;i<=dig.size();i++) {
    if(dig[i-1]==0) {
      for(int j=0;j<4;j++)
        dp[i][j][0] = dp[i-1][j][0];
    }
    else {
      for(int j=1;j<4;j++)
        dp[i][j][0] = dp[i-1][j-1][0];
    }
  }
  for(int i=1;i<=dig.size();i++) {
    for(int j=0;j<dig[i-1];j++) {
      //diverging now
      if(j!=0) {
        for(int k=1;k<4;k++)
          dp[i][k][1]+=dp[i-1][k-1][0];
      }
      else {
        for(int k=0;k<4;k++)
          dp[i][k][1]+=dp[i-1][k][0];
      }
    }
    for(int j=0;j<=9;j++) {
      //already broke
      if(j!=0) {
        for(int k=1;k<4;k++)
          dp[i][k][1]+=dp[i-1][k-1][1];
      }
      else {
        for(int k=0;k<4;k++)
          dp[i][k][1]+=dp[i-1][k][1];
      }
    }
  }
  ll ans = 0;
  for(int k=0;k<4;k++)
    ans+=dp[dig.size()][k][0]+dp[dig.size()][k][1];
  return ans;
}
int main() {
  int t; cin >> t;
  while(t--) {
    ll l,r; cin >> l >> r;
    cout << get(r)-get(l-1) << "\n";
  }
}