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

const int n = 5500;

int N, M;
int dp[n][n];
string A, B;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  cin >> A >> B;
  A = "x" + A;
  B = "x" + B;
  int res = 0;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=M; j++){
      if(A[i] == B[j]){
        dp[i][j] = dp[i-1][j-1] + 2;
      }
      else{
        dp[i][j] = max(0, max(dp[i-1][j]-1, dp[i][j-1]-1));
      }
      res = max(res, dp[i][j]);
    }
  }
  cout << res << "\n";
}