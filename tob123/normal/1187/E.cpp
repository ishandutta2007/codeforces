#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((ll) (x).size())

typedef long long ll;

const ll n = 2e5+10;

ll N;
vector<int> G[n];

ll S[n];
ll SS[n];
ll best;

void dfs(int cur, int par){
  S[cur] = 1;
  for(int x : G[cur]){
    if(x==par)
      continue;
    dfs(x, cur);
    S[cur] += S[x];
    SS[cur] += SS[x];
  }
  SS[cur] += S[cur];
}

void dfs2(int cur, int par, ll v){
  best = max(best, v+SS[cur]-S[cur]+N);
  for(int x : G[cur]){
    if(x == par){
      continue;
    }
    ll newv = v + SS[cur] - SS[x] - S[cur] + N - S[x];
    dfs2(x, cur, newv);
  }
}

int main(){
  cin >> N;
  for(int i=0; i<N-1; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0, -1);
  dfs2(0, -1, 0);
  cout << best << endl;

  return 0;
}