/**
 *    author:  tourist
 *    created: 23.11.2021 19:02:19       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> p(n, -1);
  vector<int> sg(n);
  function<void(int)> Dfs = [&](int v) {
    sg[v] = 0;
    for (int u : g[v]) {
      if (u != p[v]) {
        p[u] = v;
        Dfs(u);
        sg[v] ^= sg[u] + 1;
      }
    }
  };
  Dfs(0);
  vector<bool> alive(n, true);
  int ans = sg[0] + 1;
  int V = 0;
  for (int i = 0; i < n; i++) {
    vector<int> seq;
    int x = i;
    while (x != -1 && alive[x]) {
      seq.push_back(x);
      V += 1;
      alive[x] = false;
      x = p[x];
    }
    reverse(seq.begin(), seq.end());
    for (int v : seq) {
      ans ^= sg[v] + 1;
      for (int u : g[v]) {
        if (p[u] == v) {
          ans ^= sg[u] + 1;
        }
      }
    }
    int res = ans;
    int E = (V - 1);
    if (E % 2 == 1) {
      res ^= 1;
    }
    cout << (res > 0 ? 1 : 2);
  }
  cout << '\n';
  return 0;
}