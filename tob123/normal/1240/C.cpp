#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 5e5+10;

int Q, N, K;
vector<pii> G[n];
ll dp[n][2];

void dfs(int cur, int par){
  ll sum = 0;
  for(auto p : G[cur]){
    if(p.first != par){
      dfs(p.first, cur);
      sum += dp[p.first][0];
    }
  }
  vector<ll> val;
  for(auto p : G[cur]){
    if(p.first != par){
      ll x = dp[p.first][1]-dp[p.first][0]+p.second;
      if(x > 0)
        val.push_back(x);
    }
  }
  sort(val.rbegin(), val.rend());
  for(int i=0; i<sz(val) && i < K-1; i++){
    sum += val[i];
  }
  dp[cur][1] = sum;
  if(K-1 < sz(val))
    sum += val[K-1];
  dp[cur][0] = sum;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> Q;
  while(Q--){
    cin >> N >> K;
    for(int i=0; i<N; i++){
      G[i].clear();
    }
    for(int i=0; i<N-1; i++){
      int u, v; ll w;
      cin >> u >> v >> w;
      u--; v--;
      G[u].push_back({v,w});
      G[v].push_back({u,w});
    }
    dfs(0, -1);
    cout << dp[0][0] << "\n";
  }

  return 0;
}