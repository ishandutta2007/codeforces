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
    ll sum = 0;
    ll mx = 0;
    vector<ll> A(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
      sum += A[i];
      mx = max(mx, A[i]);
    }
    ll res = mx*(N-1) - sum;
    if(res < 0){
      res = res%(N-1);
    }
    if(res < 0){
      res += N-1;
    }
    cout << res << "\n";
  }
}