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
  ll K;
  cin >> T;
  while(T--){
    cin >> N >> K;
    vector<int> A(N);
    pii p = {1e9, -1e9};
    for(int i=0; i<N; i++){
      cin >> A[i];
      p.first = min(p.first, A[i]);
      p.second = max(p.second, A[i]);
    }
    if(K == 1){
      for(int i=0; i<N; i++){
        A[i] = p.second - A[i];
      }
    }
    else if(K > 1 && K%2){
      for(int i=0; i<N; i++){
        A[i] = p.second - A[i];
      }
    }
    else if(K > 1 && K%2 == 0){
      int x = p.second - p.first;
      for(int i=0; i<N; i++){
        A[i] = x - (p.second - A[i]);
      }
    }
    for(int i=0; i<N; i++)
      cout << A[i] << " ";
    cout << "\n";
  }
}