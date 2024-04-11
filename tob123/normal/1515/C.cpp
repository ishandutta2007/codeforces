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
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> h(N);
    for(int i=0; i<N; i++){
      cin >> h[i];
    }
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    vector<int> H(M);
    for(int i=0; i<M; i++){
      PQ.push({0, i});
    }
    cout << "YES\n";
    for(int i=0; i<N; i++){
      auto [val, ind] = PQ.top();
      PQ.pop();
      H[ind] += h[i];
      PQ.push({H[ind], ind});
      cout << ind+1 << " ";
    }
    cout << "\n";
  }
}