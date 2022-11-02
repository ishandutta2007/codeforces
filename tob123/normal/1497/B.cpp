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
  int T, N, M;
  cin >> T;
  while(T--){
    cin >> N >> M;
    vector<int> A(M);
    for(int i=0; i<N; i++){
      int x;
      cin >> x;
      A[x%M]++;
    }
    int res = 0;
    if(M%2 == 0 && A[M/2])
      res++;
    if(A[0])
      res++;
    for(int i=1; 2*i<M; i++){
      if(A[i] | A[M-i]){
        int x = min(A[i], A[M-i]);
        int y = max(A[i], A[M-i]);
        res += max(1, y-x);
      }
    }
    cout << res << "\n";
  }
}