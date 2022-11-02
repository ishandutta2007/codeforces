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
  int N, T;
  cin >> T;
  while(T--){
    cin >> N;
    vector<int> A(N);
    vector<int> nc;
    for(int i=0; i<N; i++){
      cin >> A[i];
      if(i+1 != A[i])
        nc.push_back(i);
    }
    if(sz(nc) == 0){
      cout << 0 << "\n";
    }
    else if(nc.back()-nc[0] != sz(nc)-1){
      cout << 2 << "\n";
    }
    else{
      cout << 1 << "\n";
    }
  }
}