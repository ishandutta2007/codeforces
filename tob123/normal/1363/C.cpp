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

const int n = 1e4+10;

int T, N, X;
vector<int> G[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> X;
    X--;
    for(int i=0; i<N; i++)
      G[i].clear();
    for(int i=0; i<N-1; i++){
      int u, v;
      cin >> u >> v;
      u--; v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    if(N%2==0 || sz(G[X]) <= 1){
      cout << "Ayush\n";
    }
    else{
      cout << "Ashish\n";
    }
  }
}