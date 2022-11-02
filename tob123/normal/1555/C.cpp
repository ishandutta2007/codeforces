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
  int T;
  cin >> T;
  while(T--){
    int M;
    cin >> M;
    vector<vector<ll>> A(2);
    for(int i=0; i<2; i++){
      A[i].resize(M+1);
      A[i][0] = 0;
      for(int j=1; j<=M; j++){
        cin >> A[i][j];
        if(j > 0){
          A[i][j] += A[i][j-1];
        }
      }
    }
    ll bst = A[1][M];
    for(int i=1; i<=M; i++){
      bst = min(bst, max(A[0][M]-A[0][i], A[1][i-1]));
    }
    cout << bst << "\n";
  }
}