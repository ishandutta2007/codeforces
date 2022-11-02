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

int T, N;
vector<vector<int>> G;
vector<char> L, E;
int res;

void dfs(int cur, int par){
  L[cur] = false;
  E[cur] = true;
  int cntL = 0;
  int ch = 0;
  for(int x : G[cur]){
    if(x == par) continue;
    dfs(x, cur);
    L[cur] |= E[x];
    E[cur] &= L[x];
    cntL += L[x];
    ch++;
  }
  cntL =  max(0, min(ch-1, cntL));
  res -= cntL;
  if(ch == 0)
    res++;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    G.resize(N);
    L.resize(N);
    E.resize(N);
    fill(G.begin(), G.end(), vector<int>());
    for(int i=0; i<N-1; i++){
      int u, v;
      cin >> u >> v;
      u--; v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    res = 0;
    dfs(0, -1);
    cout << res << "\n";
  }
}