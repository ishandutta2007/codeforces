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
    vector<ll> A(N+1);
    ll s = 0;
    vector<tuple<int,int,ll>> X;
    int fst = 0;
    for(int i=1; i<=N; i++){
      cin >> A[i];
      s += A[i];
      if(A[i] >= i){
        fst = i;
      }
    }
    if(s % N != 0){
      cout << -1 << "\n";
      continue;
    }
    if(fst != 1){
      X.emplace_back(fst, 1, A[fst]/fst);
      A[1] += A[fst] - A[fst]%fst;
      A[fst] %= fst;
    }
    s /= N;
    vector<pii> B;
    for(int i=2; i<=N; i++){
      if(A[i]%i == 0)
        B.emplace_back(0, i);
      else
        B.emplace_back(i-A[i]%i, i);
    }
    sort(B.begin(), B.end());
    for(auto [z, ind] : B){
      if(z <= A[1]){
        X.emplace_back(1, ind, z);
        X.emplace_back(ind, 1, (A[ind]+ind-1)/ind);
        A[1] += A[ind];
        A[ind] = 0;
      }
    }
    bool pos = true;
    for(int i=2; i<=N; i++){
      if(A[i] > s){
        pos = false;
      }
      X.emplace_back(1, i, s-A[i]);
      A[1] -= s-A[i];
    }
    if(pos && A[1] == s){
      cout << sz(X) << "\n";
      for(auto [i, j, x] : X)
        cout << i << " " << j << " " << x << "\n";
    }
    else
      cout << -1 << "\n";
  }
}