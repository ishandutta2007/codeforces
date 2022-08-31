#include<bits/stdc++.h>
using namespace std;

#define ll long long
int n,a,b,k;

ll MOD = 1000000007;
ll pref[5005][2],dp[5005][2];

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
  cin >> n >> a >> b >> k;
  for(int i = 0; i < n+5; i++){ 
    pref[i][0] = pref[i][1] = dp[i][0] = dp[i][1] = 0;
  }
  if (b < a){
    a = n+1-a;
    b = n+1-b;
  }
  dp[a][0] = 1;
  for(int i = a; i < b; i++) pref[i][0] = 1;
  for(int j = 1; j <= k; j++){
    for(int i = 1; i < b; i++){
      dp[i][j%2] = (pref[(b+i-1)/2][(j-1)%2]-dp[i][(j-1)%2]+MOD)%MOD; 
      pref[i][j%2] = (pref[i-1][j%2]+dp[i][j%2])%MOD;
      // cout << i << " " << j << " " << dp[i][j%2] << endl;
    }
  }
  cout << pref[b-1][k%2] << endl;
}