#include <bits/stdc++.h>
using namespace std;

const long long MOD=1000000007;
int N;

long long dp[5001][5001];


int main(){
  cin >> N;
  char c;
  dp[0][0] = 1;
  for(int i=1; i<N; i++){
    cin >> c;
    if(c == 'f'){
      for(int j=0; j<N; j++){
        dp[i][j+1] = dp[i-1][j];
      }
    }
    else{
      for(int j=N-1; j>=0; j--){
        dp[i][j] = (dp[i][j+1] + dp[i-1][j]) % MOD;
      }
    }
  }
  long long res = 0;
  for(int i=0; i<=N; i++){
    res += dp[N-1][i];
  }
  res %= MOD;
  cout << res << endl;

  return 0;
}