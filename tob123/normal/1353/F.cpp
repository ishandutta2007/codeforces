#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 110;
const ll INF = 1e18;

int T, N, M;
ll A[n][n];
ll dp[n][n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
      for(int j=1; j<=M; j++){
        cin >> A[i][j];
      }
    }
    ll best = INF;
    for(int i=0; i<=N; i++){
      dp[i][0] = INF;
    }
    for(int j=0; j<=M; j++){
      dp[0][j] = INF;
    }
    dp[0][1] = 0;
    for(int i=1; i<=N; i++){
      for(int j=1; j<=M; j++){
        ll b = A[i][j]-i-j;
        for(int i=1; i<=N; i++){
          for(int j=1; j<=M; j++){
            if(A[i][j] < b+i+j)
              dp[i][j] = INF;
            else{
              dp[i][j] = A[i][j]-(b+i+j) + min(dp[i-1][j], dp[i][j-1]);
            }
          }
        }
        best = min(best, dp[N][M]);
      }
    }
    cout << best << "\n";
  }
}