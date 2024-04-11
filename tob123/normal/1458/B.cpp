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
const int MAX = 1e4+10;
const int K = 101;

int dp[MAX][K];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  int s = 0;
  for(int i=0; i<N; i++){
    cin >> A[i] >> B[i];
    s += B[i];
  }
  for(int i=0; i<MAX; i++)
    for(int j=0; j<K; j++)
      dp[i][j] = -INF;
  dp[0][0] = 0;
  for(int i=0; i<N; i++){
    for(int j=MAX-1; j>=A[i]; j--){
      for(int k=K-1; k>0; k--){
        dp[j][k] = max(dp[j][k], dp[j-A[i]][k-1]+B[i]);
      }
    }
  }
  /*
  for(int i=0; i<=22; i++){
    for(int j=0; j<=3; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  */

  vector<int> curM(N+1, -INF);
  vector<int> res(N+1);
  for(int i=MAX-1; i>=0; i--){
    for(int j=1; j<=N; j++){
      curM[j] = max(curM[j], dp[i][j]);
      res[j] = max(res[j], min(2*i, 2*curM[j]+s-curM[j]));
    }
  }
  for(int i=1; i<=N; i++){
    cout << res[i]/2 << "." << (res[i]%2 ? "5" : "0") << " ";
  }
  cout << endl;
}