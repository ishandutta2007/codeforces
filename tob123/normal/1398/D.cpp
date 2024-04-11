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

const int n = 220;

int R, G, B;
ll dp[n][n][n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> G >> B;
  vector<int> lr(R), lg(G), lb(B);
  for(int i=0; i<R; i++){
    cin >> lr[i];
  }
  for(int i=0; i<G; i++){
    cin >> lg[i];
  }
  for(int i=0; i<B; i++){
    cin >> lb[i];
  }
  sort(lr.begin(), lr.end());
  sort(lg.begin(), lg.end());
  sort(lb.begin(), lb.end());
  for(int i=0; i<=R; i++){
    for(int j=0; j<=G; j++){
      for(int k=0; k<=B; k++){
        if(i>0 && j>0){
          dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k]+lr[i-1]*lg[j-1]);
        }
        if(i>0 && k>0){
          dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]+lr[i-1]*lb[k-1]);
        }
        if(k>0 && j>0){
          dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]+lb[k-1]*lg[j-1]);
        }
      }
    }
  }
  cout << dp[R][G][B] << "\n";
}