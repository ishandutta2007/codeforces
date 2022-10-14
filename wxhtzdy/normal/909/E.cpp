/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 11:48:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> g(n);
  vector<int> in(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[v].push_back(u);
    in[u] += 1;
  }  
  vector<int> que;
  vector<int> dp(n);
  for (int i = 0; i < n; i++) {
    if (in[i] == 0) {
      que.push_back(i); 
      dp[i] = a[i];
    }
  }
  for (int b = 0; b < (int) que.size(); b++) {
    int i = que[b];  
    for (int j : g[i]) {
      in[j] -= 1;
      if (in[j] == 0) {
        que.push_back(j);
      }
    }
  }
  for (int b = 0; b < (int) que.size(); b++) {
    int i = que[b];
    for (int j : g[i]) {
      dp[j] = max(dp[j], dp[i] + (a[i] == 0 && a[j] == 1));
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}