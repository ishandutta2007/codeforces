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
  ll N, T;
  cin >> T;
  while(T--){
    cin >> N;
    bool found = false;
    for(ll i=2; i*i<=N; i++){
      if(N%i == 0){
        cout << N/i << " " << N-N/i << "\n";
        found = true;
        break;
      }
    }
    if(!found){
      cout << 1 << " " << N-1 << "\n";
    }
  }
}