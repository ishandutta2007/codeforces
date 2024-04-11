/**
 *    author:  wxhtzdy
 *    created: 04.06.2022 11:35:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
  }         
  vector<int> id(n, -1);
  for (int i = 0; i < n; i++) {
    if (id[i] != -1) {
      continue;
    }        
    int x = i;
    while (id[x] == -1) {
      id[x] = i;
      x = p[x];
    }
  }
  vector<int> x(m);
  vector<int> y(m);
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i];
    --x[i]; --y[i];
  }
  vector<vector<int>> ops(n);
  for (int i = 0; i < m; i++) {
    ops[id[x[i]]].push_back(i);
  }
  vector<int> order(n);
  vector<vector<int>> my(n);
  vector<int> deg(m);
  vector<vector<int>> g(m);
  for (int i = 0; i < n; i++) {
    if (ops[i].empty()) {
      continue;
    }
    int T = 0;
    int j = i;
    vector<int> cyc;
    while (order[j] == 0) {
      cyc.push_back(j);
      order[j] = ++T;
      j = p[j];
    }     
    for (int j : ops[i]) {
      if (order[x[j]] > order[y[j]]) {
        swap(x[j], y[j]);
      }
      my[x[j]].push_back(j);
      my[y[j]].push_back(j);
    }
    for (int j : cyc) {
      sort(my[j].begin(), my[j].end(), [&](int p, int q) {
        int ix = (x[p] ^ y[p] ^ j);
        int jx = (x[q] ^ y[q] ^ j);
        int dx = (order[ix] - order[j] + n) % n;
        int dy = (order[jx] - order[j] + n) % n;
        return dx < dy;
      });         
      for (int p = 0; p + 1 < (int) my[j].size(); p++) {
        g[my[j][p]].push_back(my[j][p + 1]);
        deg[my[j][p + 1]] += 1;
      }
    }
  }
  vector<int> que;
  for (int i = 0; i < m; i++) {
    if (deg[i] == 0) {
      que.push_back(i);
    }
  }
  for (int b = 0; b < (int) que.size(); b++) {
    int i = que[b];
    for (int j : g[i]) {
      deg[j]--;
      if (deg[j] == 0) {
        que.push_back(j);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << que[i] + 1;
  }                  
  cout << '\n';
  return 0;
}