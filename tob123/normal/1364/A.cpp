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
  for(int i=0; i<T; i++){
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    int sum = 0;
    for(int i=0; i<N; i++){
      cin >> A[i];
      (sum += A[i]) %= X;
    }
    if(sum != 0){
      cout << N << "\n";
    }
    else{
      int best = 0;
      for(int i=0; i<N; i++){
        if(A[i]%X != 0)
          best = max(best, N-i-1);
      }
      for(int i=N-1; i>=0; i--){
        if(A[i]%X != 0)
          best = max(best, i);
      }
      if(best == 0)
        cout << -1 << endl;
      else
        cout << best << endl;
    }
  }
}