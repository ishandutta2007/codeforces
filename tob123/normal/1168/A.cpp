#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

const int INF = 1e6;

int N, M;
int A[300003], dp[300003];

bool pos(int x){
  dp[0] = (x+A[0] >= M) ? 0 : A[0];
  for(int i=1; i<N; i++){
    if(A[i] <= dp[i-1]){
      if(A[i]+x >= dp[i-1]){
        dp[i] = dp[i-1];
      }
      else{
        dp[i] = INF;
      }
    }
    else{
      if(A[i]+x >= dp[i-1]+M){
        dp[i] = dp[i-1];
      }
      else{
        dp[i] = A[i];
      }
    }
  }
  return dp[N-1] != INF;
}

int main(){
  cin >> N >> M;
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  int l = 0, r = M;
  while(l < r){
    int m = (l+r)/2;
    if(pos(m)){
      r = m;
    }
    else{
      l = m+1;
    }
  }

  cout << l << endl;

  return 0;
}