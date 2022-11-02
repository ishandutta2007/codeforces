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
    vector<int> A(N);
    int s = 0;
    for(int i=0; i<N; i++){
      cin >> A[i];
      s += A[i];
    }
    if(s == 0){
      cout << "NO\n";
    }
    else{
      if(s < 0)
        sort(A.begin(), A.end());
      else
        sort(A.rbegin(), A.rend());
      cout << "YES\n";
      for(int x : A)
        cout << x << " ";
      cout << "\n";
    }
  }
}