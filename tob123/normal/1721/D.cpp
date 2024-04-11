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
    vector<int> A(N), B(N);
    for(auto& x : A) cin >> x;
    for(auto& x : B) cin >> x;
    int res = 0;
    for(int b=29; b>=0; b--){
      res |= (1<<b);
      map<int,int> M;
      for(int x : A){
        M[x&res]++;
      }
      for(int x : B){
        M[(x&res)^res]--;
      }
      bool works = true;
      for(auto [k,v] : M){
        works &= v==0;
      }
      if(!works)
        res ^= (1<<b);
    }
    cout << res << "\n";
  }
}