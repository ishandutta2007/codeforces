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

const int n = 1e5+10;

int T, N, a, b, da, db;
vector<int> G[n];
int D[n];

void dfs(int cur, int par){
  for(int x : G[cur]){
    if(x != par){
      D[x] = D[cur]+1;
      dfs(x, cur);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> a >> b >> da >> db;
    a--; b--;
    for(int i=0; i<N; i++)
      G[i].clear();
    for(int i=0; i<N-1; i++){
      int u, v;
      cin >> u >> v;
      u--; v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    D[a] = 0;
    dfs(a, -1);
    int toB = D[b];
    int mxi = 0;
    for(int i=0; i<N; i++){
      if(D[i] > D[mxi])
        mxi = i;
    }
    D[mxi] = 0;
    dfs(mxi, -1);
    mxi = 0;
    for(int i=0; i<N; i++){
      if(D[i] > D[mxi])
        mxi = i;
    }
    if(da >= toB || db <= da*2 || D[mxi] <= da*2)
      cout << "Alice\n";
    else
      cout << "Bob\n";
  }
}