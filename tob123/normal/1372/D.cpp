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
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
    if(i > 1)
      A[i] += A[i-2];
  }
  ll mx = A[N-1];
  for(int i=1; i<N; i++){
    ll cur = A[i-1];
    if(i % 2){
      cur += A[N-2];
      if(i > 1)
        cur -= A[i-2];
    }
    else{
      cur += A[N-1];
      if(i > 1)
        cur -= A[i-2];
    }
    mx = max(cur, mx);
  }
  cout << mx << endl;
}