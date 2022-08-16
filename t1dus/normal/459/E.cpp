#include<bits/stdc++.h>
using namespace std;

int n,m;
int dp[300005][2];
vector<pair<int,int> > w[100005];

int main(){
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int u,v,l;cin >> u >> v >> l;
    w[l].push_back({u,v});
  }
  for(int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = 0;
  for(int i = 1; i <= 100000; i++){
    for(int j = 0; j < w[i].size(); j++){
      dp[w[i][j].second][1] = 0;
    }
    for(int j = 0; j < w[i].size(); j++){
      dp[w[i][j].second][1] = max(dp[w[i][j].second][1],dp[w[i][j].first][0]+1);
    }
    for(int j = 0; j < w[i].size(); j++){
      dp[w[i][j].second][0] = max(dp[w[i][j].second][0],dp[w[i][j].second][1]);
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) ans = max(ans,dp[i][0]); cout << ans;
}