#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 998244353;
const int MAXN = 1e4+10;

ll dp[2][MAXN];
string S, T;
int N, M;

void printDp(int ind){
  for(int i=0; i<=M; i++){
    cout << dp[ind][i] << " ";
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> S >> T;
  N = sz(S); M = sz(T);
  for(int i=0; i<=M; i++){
    dp[1][i] = 1;
  }
  int a, b;
  //printDp(1);
  ll res = 0;
  for(int i=0; i<N; i++){
    a = i%2; b = 1-a;
    for(int j=0; j<=M; j++)
      dp[a][j] = 0;
    for(int j=0; j<=M; j++){
      if(j && S[i] == T[j-1]){
        (dp[a][j-1] += dp[b][j]) %= MOD;
      }
      if(j+i < M && S[i] == T[j+i]){
        (dp[a][j] += dp[b][j]) %= MOD;
      }
      else if(j+i >= M)
        (dp[a][j] += dp[b][j]) %= MOD;
    }
    (dp[a][M] += dp[b][M]) %= MOD;
    if(i >= M-1)
      (res += dp[a][0]) %= MOD;
    //printDp(i%2);
  }
  cout << res << endl;
}