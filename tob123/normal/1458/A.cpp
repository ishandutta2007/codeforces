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
  int N, M;
  cin >> N >> M;
  vector<ll> A(N), B(M);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  ll g = 0;
  for(int i=1; i<N; i++){
    A[i] -= A[0];
    g = __gcd(g, A[i]);
  }
  //cout << g << endl;
  for(int i=0; i<M; i++){
    cin >> B[i];
  }
  for(int i=0; i<M; i++){
    cout << __gcd(g, B[i]+A[0]) << " ";
  }
  cout << "\n";
}