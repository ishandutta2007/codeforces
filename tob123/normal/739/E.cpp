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

const int n = 2200;
const double INF = 1e10;

int N, A, B;
vector<double> P, U, X;
vector<vector<double>> dp;
vector<vector<int>> cnt;

int solve1(double c){
  for(int i=1; i<=N; i++){
    for(int j=0; j<=B; j++){
      dp[i][j] = dp[i-1][j]; cnt[i][j] = cnt[i-1][j];
      if(dp[i][j] < dp[i-1][j]+P[i]-c)
        dp[i][j] = dp[i-1][j]+P[i]-c, cnt[i][j] = cnt[i-1][j]+1;
      if(j > 0){
        if(dp[i][j] < dp[i-1][j-1]+U[i])
          dp[i][j] = dp[i-1][j-1]+U[i], cnt[i][j] = cnt[i-1][j-1];
        if(dp[i][j] < dp[i-1][j-1]+X[i]-c)
          dp[i][j] = dp[i-1][j-1]+X[i]-c, cnt[i][j] = cnt[i-1][j-1]+1;
      }
    }
  }
  return cnt[N][B];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> A >> B;
  P.resize(N+1);
  U.resize(N+1);
  X.resize(N+1);
  cnt = vector<vector<int>>(N+1, vector<int>(B+1));
  dp = vector<vector<double>>(N+1, vector<double>(B+1));
  for(int i=0; i<N; i++){
    cin >> P[i+1];
  }
  for(int i=0; i<N; i++){
    cin >> U[i+1];
    X[i+1] = P[i+1]+U[i+1]-P[i+1]*U[i+1];
  }
  double lo=0, hi=2000;
  for(int it=0; it<60; it++){
    double m = (lo+hi)/2;
    if(solve1(m) >= A){
      lo = m;
    }
    else{
      hi = m;
    }
  }
  solve1(hi);
  //solve2(hi, hi2);
  cout << fixed << setprecision(10) << dp[N][B]+hi*A << endl;
  //cout << hi << " " << cnt[N][B] << " " << dp[N][B] << endl;
  //print(cnt);
  //print(dp);
}