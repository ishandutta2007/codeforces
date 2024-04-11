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

const ll MOD = 998244353;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<ll> l(N), r(N);
  for(int i=0; i<N; i++){
    cin >> l[i] >> r[i];
  }
  vector<ll> res(M+1);
  for(int t=1; t<=M; t++){
    vector<ll> x(N);
    bool f = false;
    int cnt = M/t;
    for(int i=0; i<N; i++){
      x[i] = r[i]/t - (l[i]+t-1)/t;
      cnt -= (l[i]+t-1)/t;
      if(x[i] < 0){
        f = true;
        res[t] = 0;
      }
    }
    if(!f && cnt >= 0){
      vector<vector<ll>> dp(N+1, vector<ll>(cnt+1, 0));
      for(int i=0; i<=cnt; i++)
        dp[N][i] = 1;
      for(int i=N-1; i>=0; i--){
        dp[i][cnt] = 0;
        for(int j=0; j<=min((ll)cnt, x[i]); j++){
          (dp[i][cnt] += dp[i+1][cnt-j]) %= MOD;
        }
        for(int j=cnt-1; j>=0; j--){
          dp[i][j] = (dp[i][j+1]-dp[i+1][j+1]+MOD) % MOD;
          if(j-x[i] >= 0)
            (dp[i][j] += dp[i+1][j-x[i]]) %= MOD;
        }
      }
      res[t] = dp[0][cnt];
    }
  }
  for(int i=M; i>=1; i--){
    for(int j=2*i; j<=M; j+=i){
      (res[i] += MOD - res[j]) %= MOD;
    }
  }
  cout << res[1] << endl;
}