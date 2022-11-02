#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

const int n = 3001;

int T, N;
int A[n];
int dp[n][n];
int stck[22];
int val[22];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    for(int i=1; i<N; i++)
      dp[i][i-1] = 0;
    for(int l=N-1; l>=0; l--){
      int cnt = 0;
      dp[l][l] = 0;
      dp[l][l+1] = A[l+1] == A[l] ? 0 : 1;
      if(A[l+1] == A[l]){
        stck[cnt++] = l+1;
        val[0] = 0;
      }
      for(int r=l+2; r<N; r++){
        dp[l][r] = 1 + dp[l+1][r];
        if(A[r] == A[l]){
          stck[cnt] = r;
          dp[l][r] = 1+dp[l+1][r-1];
        }
        for(int i=0; i<cnt; i++){
          int x = stck[i];
          dp[l][r] = min(dp[l][r], val[i] + dp[x][r]);
        }
        if(A[r] == A[l]){
          val[cnt++] = dp[l][r];
        }
      }
    }
    cout << dp[0][N-1] << "\n";
  }
}