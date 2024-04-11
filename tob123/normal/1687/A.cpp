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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N+2);
    for(int i=1; i<=N; i++){
      cin >> A[i];
      A[i] += A[i-1];
    }
    if(K > N){
      ll cnt = K*N - N*(N+1)/2 + A[N];
      cout << cnt << endl;
    }
    else{
      ll cnt = K*(K-1)/2;
      ll mx = 0;
      for(int i=K; i<=N; i++){
        mx = max(mx, A[i]-A[i-K]);
      }
      cout << mx + cnt << endl;
    }
  }
}