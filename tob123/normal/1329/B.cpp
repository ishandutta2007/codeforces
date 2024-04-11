#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 50;

int T;
ll D, M;
ll dp[n][n];

void printDp(){
  for(int i=0; i<10;i++){
    cout << i << ": ";
    for(int j=0; j<10; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> D >> M;
    dp[0][0] = 1;
    ll sum = 0;
    for(int i=1; i<=32; i++){
      for(int k=1; k<=30; k++){
        dp[i][k] = 0;
        for(int j=0; j<k; j++){
          (dp[i][k] += dp[i-1][j]) %= M;
        }
        (dp[i][k] *= max(0ll, min(D,(1ll<<k)-1)+1-(1ll<<(k-1)))) %= M;
        (sum += dp[i][k]) %= M;
      }
    }
    //printDp();
    cout << sum << endl;
  }

  return 0;
}