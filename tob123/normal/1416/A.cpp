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
    vector<vector<int>> A(N);
    for(int i=0; i<N; i++){
      int x;
      cin >> x;
      x--;
      A[x].push_back(i);
    }
    vector<int> B(N+2, 10000000);
    for(int i=0; i<N; i++){
      int lst = -1;
      A[i].push_back(N);
      int m = 0;
      for(int z : A[i]){
        m = max(m, z-lst);
        lst = z;
      }
      B[m] = min(B[m], i);
    }
    for(int i=2; i<=N; i++){
      B[i] = min(B[i], B[i-1]);
    }
    for(int i=1; i<=N; i++){
      cout << (B[i] > N ? -1 : B[i]+1) << " ";
    }
    cout << "\n";
  }
}