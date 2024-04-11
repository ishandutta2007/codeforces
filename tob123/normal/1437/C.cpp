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

const int INF = 1e8;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int Q, N;
  cin >> Q;
  while(Q--){
    cin >> N;
    vector<int> A(N+1);
    for(int i=0; i<N; i++)
      cin >> A[i];
    A[N] = 2*N;
    sort(A.begin(), A.end());
    vector<vector<int>> dp(N+2, vector<int>(2*N+1, INF));
    dp[0][0] = 0;
    for(int i=0; i<=N; i++){
      int t = A[i];
      int b = dp[i][0];
      for(int j=0; j<2*N; j++){
        b = min(b, dp[i][j]);
        dp[i+1][j+1] = b + abs(j+1-t);
      }
    }
    cout << dp[N+1][2*N] << "\n";
  }
}