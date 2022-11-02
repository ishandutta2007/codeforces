#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<ll,int> pii;

const int n = 1010;
const ll INF = 1e13;

int N, K;
vector<int> A, B;
pii dp[n][n];

void printDp(){
  for(int i=0; i<=N; i++){
    for(int j=0; j<K; j++){
      cout << "(" << dp[i][j].first << "," << dp[i][j].second << ") ";
    }
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  ll cnt = 0;
  A.resize(N); B.resize(N);
  for(int j=0; j<=N; j++){
    for(int i=0; i<K; i++){
      dp[j][i] = {-INF, 0};
    }
  }
  dp[0][0] = {0, 0};
  for(int i=0; i<N; i++){
    cin >> A[i] >> B[i];
    for(int k=0; k<K; k++){
      int x = k+A[i];
      int y = dp[i][k].second + B[i];
      dp[i+1][x%K] = max(dp[i+1][x%K], {dp[i][k].first+x/K+y/K, y%K});
    }
    for(int j=1; j<K; j++){
      if(A[i]>=j && B[i]>=K-j){
        for(int k=0; k<K; k++){
          int x = k+A[i]-j;
          int y = dp[i][k].second + B[i] - K + j;
          dp[i+1][x%K] = max(dp[i+1][x%K], {dp[i][k].first+1+x/K+y/K, y%K});
        }
      }
    }
  }
  //printDp();
  ll mx = 0;
  for(int i=0; i<K; i++){
    mx = max(mx, dp[N][i].first);
  }
  cout << cnt+mx << endl;
}