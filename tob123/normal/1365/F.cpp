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
    vector<vector<int>> A(2, vector<int>(N));
    for(int j=0; j<2; j++)
      for(int i=0; i<N; i++)
        cin >> A[j][i];
    vector<vector<pii>> p(2);
    for(int j=0; j<2; j++){
      for(int i=1; 2*i<=N; i++){
        p[j].push_back({min(A[j][i-1], A[j][N-i]), max(A[j][i-1], A[j][N-i])});
      }
      sort(p[j].begin(), p[j].end());
    }
    bool pos = p[0] == p[1];
    if(N%2)
      pos &= A[0][N/2] == A[1][N/2];
    cout << (pos ? "Yes\n" : "No\n");
  }
}