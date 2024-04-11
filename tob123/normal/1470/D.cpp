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

const int n = 1e6+10;

int N, M;
vector<int> G[n];
bool vis[n];
bool taken[n];
int cnt = 0;
vector<int> res;

void dfs(int cur){
  cnt++;
  vis[cur] = true;
  for(int x : G[cur]){
    if(!vis[x])
      dfs(x);
  }
}

void dfs2(int cur){
  vis[cur] = true;
  bool oth = false;
  for(int x : G[cur])
    oth |= taken[x];
  if(!oth){
    res.push_back(cur);
    taken[cur] = true;
  }
  for(int x : G[cur]){
    if(!vis[x])
      dfs2(x);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    cin >> N >> M;
    for(int i=0; i<N; i++){
      G[i].clear();
      vis[i] = false;
      taken[i] = false;
      cnt = 0;
    }
    for(int i=0; i<M; i++){
      int u, v;
      cin >> u >> v;
      u--; v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(0);
    if(cnt == N){
      cout << "YES\n";
      for(int i=0; i<N; i++)
        vis[i] = false;
      res.clear();
      dfs2(0);
      cout << sz(res) << "\n";
      sort(res.begin(), res.end());
      for(int x : res)
        cout << x+1 << " ";
      cout << "\n";
    }
    else{
      cout << "NO\n";
    }
  }
}