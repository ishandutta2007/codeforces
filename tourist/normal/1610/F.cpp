/**
 *    author:  tourist
 *    created: 23.11.2021 19:24:22       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> u(m), v(m), w(m);
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i] >> w[i];
    --u[i]; --v[i];
  }
  vector<vector<int>> ones(n);
  vector<vector<int>> twos(n);
  for (int i = 0; i < m; i++) {
    if (w[i] == 1) {
      ones[u[i]].push_back(i);
      ones[v[i]].push_back(i);
    } else {
      twos[u[i]].push_back(i);
      twos[v[i]].push_back(i);
    }
  }
  vector<vector<pair<int, int>>> g(m);
  int cnt_odd = 0;
  for (int i = 0; i < n; i++) {
    auto Use = [&](vector<int>& z) {
      while (z.size() >= 2) {
        int x = z.back();
        z.pop_back();
        int y = z.back();
        z.pop_back();
        g[x].emplace_back(y, i);
        g[y].emplace_back(x, i);
      }
    };
    Use(ones[i]);
    Use(twos[i]);
    if (ones[i].size() == 1 && twos[i].size() == 1) {
      int x = ones[i][0];
      int y = twos[i][0];
      g[x].emplace_back(y, i);
      g[y].emplace_back(x, i);
    }
    if (ones[i].size() == 1) {
      cnt_odd += 1;
    }
  }
  for (int i = 0; i < m; i++) {
    assert(g[i].size() <= 2);
  }
  vector<int> res(m, -1);
  auto FindChain = [&](int i) {
    vector<int> seq(1, i);
    vector<int> vers(1, g[i][0].second);
    int p = i;
    int j = g[i][0].first;
    while (true) {
      seq.push_back(j);
      if (g[j].size() == 1) {
        break;
      }
      int q = (g[j][0] == make_pair(p, vers.back()) ? 1 : 0);
      vers.push_back(g[j][q].second);
      p = j;
      j = g[j][q].first;
    }
    res[seq[0]] = 0;
    for (int it = 1; it < (int) seq.size(); it++) {
      int pr = seq[it - 1];
      int me = seq[it];
      int ver = vers[it - 1];
      int id_pr = (u[pr] == ver ? 0 : 1);
      int id_me = (u[me] == ver ? 0 : 1);
      res[seq[it]] = (res[seq[it - 1]] ^ (id_pr == id_me ? 1 : 0));
    }
  };
  for (int i = 0; i < m; i++) {
    if (res[i] != -1) {
      continue;
    }
    if (g[i].size() == 0) {
      res[i] = 1;
      continue;
    }
    if (g[i].size() == 1) {
      FindChain(i);
    }
  }
  for (int i = 0; i < m; i++) {
    if (res[i] == -1) {
      assert(g[i].size() == 2);
      int j = g[i][1].first;
      auto it = find(g[j].begin(), g[j].end(), make_pair(i, g[i][1].second));
      assert(it != g[j].end());
      g[i].pop_back();
      g[j].erase(it);
      FindChain(i);
    }
  }
  cout << cnt_odd << '\n';
  for (int i = 0; i < m; i++) {
    cout << res[i] + 1;
  }
  cout << '\n';
  return 0;
}