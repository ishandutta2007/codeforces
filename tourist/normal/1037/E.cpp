/**
 *    author:  tourist
 *    created: 02.09.2018 18:15:55       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int,int>>> g(n);
  vector<int> from(m), to(m);
  for (int i = 0; i < m; i++) {
    cin >> from[i] >> to[i];
    from[i]--; to[i]--;
    g[from[i]].emplace_back(to[i], i);
    g[to[i]].emplace_back(from[i], i);
  }
  vector<int> alive(m, 1);
  vector<int> deg(n);
  vector<int> que;
  for (int i = 0; i < n; i++) {
    deg[i] = (int) g[i].size();
    if (deg[i] < k) {
      que.push_back(i);
    }
  }
  int b = 0;
  vector<int> res(m);
  for (int step = m - 1; step >= 0; step--) {
    while (b < (int) que.size()) {
      int i = que[b];
      for (auto &p : g[i]) {
        if (!alive[p.second]) {
          continue;
        }
        alive[p.second] = 0;
        if (deg[p.first] == k) {
          que.push_back(p.first);
        }
        deg[p.first]--;
        deg[i]--;
      }
      b++;
    }
    res[step] = n - (int) que.size();
    if (alive[step]) {
      if (deg[from[step]] == k) {
        que.push_back(from[step]);
      }
      if (deg[to[step]] == k) {
        que.push_back(to[step]);
      }
      deg[from[step]]--;
      deg[to[step]]--;
      alive[step] = 0;
    }
  }
  for (int i = 0; i < m; i++) {
    cout << res[i] << '\n';
  }
  return 0;
}