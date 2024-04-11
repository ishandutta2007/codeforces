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

const int n = 1e6;

int N;
vector<vector<pii>> G;
int S[n];
stack<int> col[n];
vector<int> edgeC[n];
vector<pii> children[n];
ll pos[n];

ll res = 0;

void dfs(int cur, int par){
  S[cur] = 1;
  for(auto [x, ei] : G[cur]){
    if(x == par) continue;
    for(int c : edgeC[ei]){
      if(sz(col[c])){
        children[col[c].top()].emplace_back(x, c);
      }
      col[c].push(x);
    }
    dfs(x, cur);
    S[cur] += S[x];
    for(int c : edgeC[ei]){
      col[c].pop();
    }
    map<int, ll> M;
    for(int c : edgeC[ei])
      M[c] = S[x];
    for(auto [ch, ec] : children[x])
      M[ec] -= S[ch];
    for(auto [ch, ec] : children[x])
      res += M[ec] * pos[ch];
    pos[x] = M.begin()->second;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  G.resize(N+1);
  for(int i=1; i<N; i++){
    int u, v, x;
    cin >> u >> v >> x;
    G[u].emplace_back(v, i);
    G[v].emplace_back(u, i);
    edgeC[i].push_back(x);
  }
  G[0].emplace_back(1, 0);
  for(int c=1; c<=N; c++)
    edgeC[0].push_back(c);

  dfs(0, -1);
  cout << res << endl;
}