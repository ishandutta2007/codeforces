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

const int n = 7000;
const ll INF = 1e17;

int N, K;
vector<vector<ll>> A;
ll bst = 0;
ll dp[n][n];

void solve(int l, int r, int dim){
  if(l == r){
    for(int i=0; i<min(K,sz(A[l])); i++){
      bst = max(bst, A[l][i]+dp[dim-1][K-i-1]);
    }
  }
  else{
    int m = (l+r)/2;
    int curD = dim;
    for(int i=m+1; i<=r; i++){
      for(int j=0; j<=K; j++){
        dp[curD][j] = dp[curD-1][j];
        //if(j) dp[curD][j] = max(dp[curD][j], dp[curD][j-1]);
        if(sz(A[i]) <= j){
          dp[curD][j] = max(dp[curD][j], dp[curD-1][j-sz(A[i])] + A[i].back());
        }
      }
      curD++;
    }
    solve(l, m, curD);
    curD = dim;
    for(int i=l; i<=m; i++){
      for(int j=0; j<=K; j++){
        dp[curD][j] = dp[curD-1][j];
        //if(j) dp[curD][j] = max(dp[curD][j], dp[curD][j-1]);
        if(sz(A[i]) <= j){
          dp[curD][j] = max(dp[curD][j], dp[curD-1][j-sz(A[i])] + A[i].back());
        }
      }
      curD++;
    }
    solve(m+1, r, curD);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  A.resize(N);
  for(int i=0; i<N; i++){
    int s;
    cin >> s;
    A[i].resize(s);
    for(int j=0; j<s; j++){
      cin >> A[i][j];
      if(j)
        A[i][j] += A[i][j-1];
    }
  }
  for(int i=0; i<=K; i++)
    dp[0][i] = -INF;
  dp[0][0] = 0;
  solve(0, N-1, 1);
  cout << bst << endl;
}