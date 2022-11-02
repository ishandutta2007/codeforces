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
    vector<int> A(101);
    for(int i=0; i<N; i++){
      int x;
      cin >> x;
      A[x]++;
    }
    for(int i=0; i<=100; i++){
      if(A[i])
        cout << i << " ";
    }
    for(int i=0; i<=100; i++){
      for(int j=1; j<A[i]; j++)
        cout << i << " ";
    }
    cout << endl;
  }
}