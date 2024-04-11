#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int n = 505;

int N;
vector<int> A;
int dp[n][n];

int main(){
  cin >> N;
  char c;
  for(int i=0; i<N; i++){
    cin >> c;
    c -= 'a';
    A.push_back(c);
    dp[1][i] = 1;
  }

  for(int len=2; len<=N; len++){
    for(int l=0; l<=N-len; l++){
      int r = l+len;
      dp[len][l] = dp[len-1][l+1]+1;
      for(int i=l+1; i<r; i++){
        if(A[i] == A[l]){
          dp[len][l] = min(dp[len][l], dp[r-i][i]+dp[i-l-1][l+1]);
        }
      }
    }
  }

  cout << dp[N][0] << endl;

  return 0;
}