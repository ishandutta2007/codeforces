/**
 *  author: milos
 *  created: 04.01.2021 12:32:41
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector<vector<int>> g(N);
vector<int> col(N), a(N, 0), b(N, 0);
int ans = 0, cnt_x = 0, cnt_y = 0;

pair<int, int> Dfs(int u, int prv) {
  int x = 0, y = 0;
  if (col[u] == 1) x += 1;
  if (col[u] == 2) y += 1;
  for (int i : g[u]) {
    if (i == prv) {
      continue;
    }
    pair<int, int> my = Dfs(i, u);
    if (my.first == cnt_x && my.second == 0) {
      ans += 1;
    }
    if (my.first == 0 && my.second == cnt_y) {
      ans += 1;
    }
    x += my.first;
    y += my.second;
  }
  return {x, y};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;           
  for (int i = 0; i < n; i++) {
    cin >> col[i];
    if (col[i] == 1) {
      cnt_x += 1;
    }
    if (col[i] == 2) {
      cnt_y += 1;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ans = 0;
  Dfs(0, -1);
  cout << ans << '\n';
  return 0;
}