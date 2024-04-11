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

const int n = 1e4+1;
bitset<n> dp[101][101];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  dp[1][1].set(0);
  for(int i=1; i<=100; i++){
    for(int j=1; j<=100; j++){
      if(i!=1 || j != 1){
        dp[i][j] = (dp[i-1][j]<<j) | (dp[i][j-1]<<i);
      }
    }
  }
  int T, N, M, K;
  cin >> T;
  while(T--){
    cin >> N >> M >> K;
    if(dp[N][M][K]) cout << "YES\n";
    else cout << "NO\n";
  }
}