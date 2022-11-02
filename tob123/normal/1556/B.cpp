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
    vector<int> A(N);
    vector<int> p(2);
    vector<vector<int>> x(2);
    for(int i=0; i<N; i++){
      cin >> A[i];
      p[A[i]%2]++;
      x[A[i]%2].push_back(i);
    }
    vector<int> res(2);
    for(int i=0; i<2; i++){
      int curI = 0;
      for(int k : x[i]){
        res[i] += abs(curI - k);
        curI += 2;
      }
    }
    if(N%2 == 0){
      if(p[0] != p[1])
        cout << -1 << "\n";
      else{
        cout << min(res[0], res[1]) << "\n";
      }
    }
    else{
      if(p[0] == p[1]+1){
        cout << res[0] << "\n";
      }
      else if(p[0] == p[1]-1){
        cout << res[1] << "\n";
      }
      else{
        cout << -1 << "\n";
      }
    }
  }
}