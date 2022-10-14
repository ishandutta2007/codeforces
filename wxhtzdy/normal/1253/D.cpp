/**
 *  author: milos
 *  created: 07.01.2021 17:11:56
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<vector<int>> g(N);
vector<bool> was(N, false);
int bot, top;

void Dfs(int u) {
  was[u] = true;
  bot = min(u, bot);
  top = max(u, top);
  for (int j : g[u]) {
    if (!was[j]) {
      Dfs(j);
    }
  }                                                                        
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  } 
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      bot = i, top = i;
      Dfs(i);        
      v.emplace_back(bot, top);
    }
  }
  int ans = 0, j = -1;
  for (auto c : v) {
    if (c.first <= j) {
      ans += 1;
    }      
    j = max(j, c.second);
  }
  cout << ans << '\n';
  return 0;
}