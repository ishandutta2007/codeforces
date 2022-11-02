#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int n = 3e5+10;
const ll MOD = 998244353;

int T, N, M;
ll sum[2];
vector<vector<int>> G;
bool vis[n];
int col[n];
ll pw[n];

void dfs(int cur, int ind){
  //cout << " " << cur;
  vis[cur] = true;
  sum[ind]++;
  col[cur] = ind;
  for(int x : G[cur]){
    if(!vis[x]){
      dfs(x, 1-ind);
    }
    else if(col[x] != (1-ind)){
      sum[0] = -1e8;
      sum[1] = -1e8;
    }
  }
}

void printG(){
  for(int i=0; i<G.size(); i++){
    cout << i << " -> ";
    for(int x : G[i]){
      cout << x << " ";
    }
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pw[0] = 1;
  for(int i=1; i<n; i++){
    pw[i] = 2*pw[i-1];
    pw[i] %= MOD;
  }
  cin >> T;
  while(T--){
    cin >> N >> M;
    G.clear();
    G = vector<vector<int>>(N, vector<int>(0));
    for(int i=0; i<M; i++){
      int u, v;
      cin >> u >> v;
      u--; v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    //printG();
    fill_n(vis, N+1, false);
    fill_n(col, N+1, -1);
    ll res = 1;
    for(int i=0; i<N; i++){
      if(!vis[i]){
        //cout << i << ": " << endl;
        sum[0] = 0;
        sum[1] = 0;
        dfs(i, 0);
        //cout << endl;
        //cout << sum[0] << ", " << sum[1] << endl;
        if(sum[0] >= 0){
          ll pos = pw[sum[1]];
          pos %= MOD;
          pos += pw[sum[0]];
          pos %= MOD;
          //cout << pos << endl;
          res *= pos;
          res %= MOD;
        }
        else{
          res = 0;
        }
      }
    }
    cout << res << "\n";
  }

  return 0;
}