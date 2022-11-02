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

const int n = 3005;

int T, N;
ll dp[n][n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    vector<int> A(N+2);
    for(int i=1; i<=N; i++)
      cin >> A[i];
    for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
        dp[i][j] = dp[i][j-1] + (A[j] == i);
      }
    }
    ll res = 0;
    for(int i=1; i<=N; i++){
      for(int j=i+1; j<=N; j++){
        res += (dp[A[i]][N]-dp[A[i]][j]) * dp[A[j]][i-1];
      }
    }
    cout << res << "\n";
  }
}