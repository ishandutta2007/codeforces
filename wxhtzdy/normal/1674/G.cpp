/**
 *    author:  wxhtzdy
 *    created: 04.06.2022 14:17:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> deg(n);
  vector<int> in(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    in[v] += 1;
  }
  vector<int> que;
  for (int i = 0; i < n; i++) {
    if (in[i] == 0) {
      que.push_back(i);
    }
  }
  for (int b = 0; b < (int) que.size(); b++) {
    int i = que[b];
    for (int j : g[i]) {
      deg[j] += 1;
      if (in[j] == deg[j]) {
        que.push_back(j);
      }
    }
  }
  reverse(que.begin(), que.end());
  vector<int> dp(n, 1);
  for (int b = 0; b < (int) que.size(); b++) {
    int i = que[b];
    if (g[i].size() >= 2) {
      for (int j : g[i]) {
        if (in[j] >= 2) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n'; 
  return 0;
}