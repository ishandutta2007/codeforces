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


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T, M;
  cin >> T;
  while(T--){
    cin >> M;
    vector<vector<int>> A(2, vector<int>(M));
    for(int i=0; i<2; i++){
      for(int j=0; j<M; j++){
        cin >> A[i][j];
        A[i][j]++;
      }
    }
    A[0][0] = 0;
    vector<vector<int>> dp(2, vector<int>(M+1));
    dp[0][M] = dp[1][M] = 0;
    for(int i=0; i<2; i++){
      for(int j=M-1; j>=0; j--){
        dp[i][j] = max(dp[i][j+1]-1, max(A[i][j], A[i^1][j]-2*(M-j)+1));
      }
      //print(dp[i]);
    }
    int bst = 2e9;
    int cur = 0;
    for(int i=0; i<M; i++){
      cur = max(cur, A[i%2][i]);
      bst = min(bst, max(cur, dp[i%2][i])+2*(M-i)-1);
      cur = max(cur+1, A[1 - i%2][i]) + 1;
    }
    cout << bst << "\n";
  }
}