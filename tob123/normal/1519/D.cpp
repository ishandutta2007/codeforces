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
  vector<ll> A(N+2), B(N+2);
  vector<ll> pre(N+2), post(N+2);
  for(int i=1; i<=N; i++){
    cin >> A[i];
  }
  for(int i=1; i<=N; i++){
    cin >> B[i];
  }
  for(int i=1; i<=N; i++){
    pre[i] = pre[i-1] + A[i]*B[i];
  }
  for(int i=N; i>=1; i--){
    post[i] = post[i+1] + A[i]*B[i];
  }
  ll bst = pre[N];
  auto f = [&](int l, int r, ll cur){
    while(l >= 1 && r <= N){
      cur += A[l]*B[r]+A[r]*B[l];
      bst = max(bst, pre[l-1]+post[r+1]+cur);
      l--; r++;
    }
  };
  for(int i=1; i<N; i++){
    f(i-1, i+1, A[i]*B[i]);
    f(i, i+1, 0);
  }
  cout << bst << "\n";
}