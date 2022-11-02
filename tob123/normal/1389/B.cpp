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
  int T, N, K, Z;
  cin >> T;
  while(T--){
    cin >> N >> K >> Z;
    vector<ll> A(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    vector<vector<ll>> dp(Z+1, vector<ll>(N));
    dp[0][0] = A[0];
    for(int i=1; i<N; i++)
      dp[0][i] = dp[0][i-1]+A[i];
    //print(dp[0]);
    for(int j=1; j<=Z; j++){
      dp[j][0] = dp[j-1][1] + A[0];
      for(int i=1; i<N-1; i++){
        dp[j][i] = A[i] + max(dp[j-1][i+1], dp[j][i-1]);
      }
      dp[j][N-1] = dp[j][N-2] + A[N-1];
      //print(dp[j]);
    }
    ll res = 0;
    for(int j=0; j<=Z; j++){
      for(int i=0; i<N; i++){
        if(i + 2*j == K)
          res = max(res, dp[j][i]);
      }
    }
    cout << res << "\n";
  }
}