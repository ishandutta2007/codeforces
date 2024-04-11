#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1010;
const ll MOD = 1e9+7;

int N, M;
ll dp[11][n][n];

void printDP(int i){
  for(int a=N; a>=1; a--){
    for(int b=1; b<=N; b++){
      cout << dp[i][a][b] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void magic(int x){
  for(int i=1; i<=N; i++){
    for(int j=N; j>=1; j--){
      dp[x][i][j] += dp[x][i-1][j] + dp[x][i][j+1] - dp[x][i-1][j+1] + MOD;
      dp[x][i][j] %= MOD;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  /*
  for(int i=1; i<=N; i++)
    for(int j=i; j<=N; j++)
      dp[0][i][j] = 1;
      */
  dp[0][1][N] = 1;
  //printDP(0);
  for(int i=1; i<=M; i++){
    magic(i-1);
    for(int a=1; a<=N; a++){
      for(int b=N; b>=a; b--){
        dp[i][a][b] = dp[i-1][a][b];
        /*
        for(int x=1; x<=a; x++){
          for(int y=b; y<=N; y++){
            dp[i][a][b] += dp[i-1][x][y];
            dp[i][a][b] %= MOD;
          }
        }
        */
      }
    }
    //printDP(i);
  }
  magic(M);
  cout << dp[M][N][1] << endl;

  return 0;
}