#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[10000005];

int main(){
  int n,x,y;
  cin >> n >> x >> y;
  
  dp[0] = 0;
  dp[1] = x;
  for(int i = 2; i <= n; i++){
    if (i%2 == 0) dp[i] = min(dp[i-1]+x,dp[i/2]+y);
    else dp[i] = min(dp[i-1]+x,dp[(i+1)/2]+x+y);
  }
  cout << dp[n] << endl;
}