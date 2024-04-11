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
  int N, M;
  string S;
  cin >> N >> M;
  cin >> S;
  S = "x" + S;
  vector<vector<int>> dp(N+1, vector<int>(6));
  for(int i=1; i<=N; i++){
    S[i] -= 'a';
    for(int j=0; j<6; j++)
      dp[i][j] = dp[i-1][j];
    dp[i][(6+i-S[i])%3]++;
    if(S[i] != 'a'){
      S[i] = 3-S[i];
      dp[i][3+(6+i-S[i])%3]++;
      S[i] = 3-S[i];
    }
  }
  for(int m=0; m<M; m++){
    int l, r;
    cin >> l >> r;
    if(r == l){
      cout << 0 << "\n";
    }
    else if(r == l+1){
      cout << (S[l] == S[r] ? 1 : 0) << "\n";
    }
    else{
      int x = 0;
      for(int i=0; i<6; i++){
        x = max(x, dp[r][i]-dp[l-1][i]);
      }
      cout << r-l+1-x << "\n";
    }
  }
}