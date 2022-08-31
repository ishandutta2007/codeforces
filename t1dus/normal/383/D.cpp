#include<bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1000000007;
int n,x,res = 0;
int dp[2][200005];

signed main(){
  
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
  cin >> n;
  for(int i = 0; i < 200005; i++) dp[0][i] = dp[1][i] = 0;
  
  dp[0][100000] = 1;
  int cur = 0;
  for(int i = 1; i <= n; i ++){
    cin >> x;
    for(int j = 100000-cur; j <= 100000+cur; j ++) dp[i%2][j] = 0;
    
    for(int j = 100000-cur; j <= 100000+cur; j ++){
      dp[i%2][j+x] += dp[(i-1)%2][j];
      dp[i%2][j+x] %= MOD;
    }
    for(int j = 100000+cur; j >= 100000-cur; j --){
      dp[i%2][j-x] += dp[(i-1)%2][j];
      dp[i%2][j-x] %= MOD;
    }
    if(i > 1) dp[i%2][x+100000] += 1,dp[i%2][100000-x] += 1;
    // cout << dp[i%2][100000] << " -\n";
    res += dp[i%2][100000]; 
    res %= MOD;
    cur += x;
    // cout << res << endl;
  }
  cout << res << endl;
}