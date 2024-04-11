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
    int N;
    cin >> N;
    int is0 = -1;
    vector<int> A(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
      if(A[i] == 0)
        is0 = i;
    }
    for(int i=0; i<=is0; i++){
      cout << i+1 << " ";
    }
    cout << N+1;
    for(int i=is0+1; i<N; i++){
      cout << " " << i+1;
    }
    cout << "\n";
  }
}