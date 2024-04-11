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
  int T, K;
  cin >> T;
  while(T--){
    cin >> K;
    vector<int> A(K+1);
    for(int i=0; i<K; i++)
      A[i] = i;
    cout << K << "\n";
    for(int i=0; i<K; i++){
      for(int j=0; j<K; j++){
        cout << A[j]+1 << " ";
      }
      cout << "\n";
      swap(A[i], A[i+1]);
    }
  }
}