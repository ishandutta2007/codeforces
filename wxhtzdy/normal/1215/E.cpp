#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    --a[i];
  }
  const int M = 20;
  vector<vector<int>> pos(M);
  for (int i = 0; i < n; i++){
    pos[a[i]].push_back(i);
  }
  vector<vector<long long>> cost(M, vector<long long>(M));
  for (int i = 0; i < M; i++){
    for (int j = 0; j < M; j++){
      if (i == j){
        continue;
      }
      if (pos[i].empty()){
        continue;
      }
      if (pos[j].empty()){
        continue;
      }
      for (int x = 0, y = 0; x < pos[i].size(); x++){
        while (y + 1 < pos[j].size() && pos[j][y + 1] < pos[i][x]) {
          y++;
        }
        if (pos[j][y] < pos[i][x]) {
          cost[i][j] += (y + 1);
        }
      }
    }
  }
  vector<long long> dp(1 << M, 1e18);
  dp[0] = 0;
  for (int i = 0; i < (1 << M); i++){
    for (int j = 0; j < M; j++){
      if (i & (1 << j)){
        continue;
      }
      long long ccost = 0;
      for (int k = 0; k < M; k++){
        if (i & (1 << k)){
          ccost += cost[k][j];
        }
      }
      dp[i ^ (1 << j)] = min(dp[i ^ (1 << j)], dp[i] + ccost);
    }
  }
  cout << dp[(1 << M) - 1];
}