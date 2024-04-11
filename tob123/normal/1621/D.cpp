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
  int T, N;
  cin >> T;
  while(T--){
    cin >> N;
    vector<vector<ll>> C(2*N, vector<ll>(2*N));
    ll sum = 0;
    for(int i=0; i<2*N; i++){
      for(int j=0; j<2*N; j++){
        cin >> C[i][j];
        if(i >= N && j >= N)
          sum += C[i][j];
      }
    }
    ll ad = min(C[0][N], min(C[0][2*N-1], min(C[N-1][N], min(C[N-1][2*N-1], min(C[N][0], min(C[N][N-1], min(C[2*N-1][0], C[2*N-1][N-1])))))));
    cout << sum+ad << endl;
  }
}