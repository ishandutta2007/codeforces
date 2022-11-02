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
  int T, N, M;
  cin >> T;
  while(T--){
    cin >> N >> M;
    vector<int> K(N), C(M);
    for(int i=0; i<N; i++){
      cin >> K[i];
      K[i]--;
    }
    for(int i=0; i<M; i++){
      cin >> C[i];
    }
    sort(K.rbegin(), K.rend());
    int ci=0;
    ll sum = 0;
    for(int k : K){
      if(ci < M && C[ci] < C[k]){
        sum += C[ci++];
      }
      else
        sum += C[k];
    }
    cout << sum << "\n";
  }
}