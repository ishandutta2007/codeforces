/**
 *    author:  tourist
 *    created: 29.04.2018 17:27:35       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector< vector<int> > g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> res;
  vector<int> q(1, 0);
  vector<int> pr(n, -1);
  pr[0] = -2;
  for (int b = 0; b < (int) q.size(); b++) {
    int i = q[b];
    for (int j : g[i]) {
      if (pr[j] == -1) {
        pr[j] = i;
        q.push_back(j);
      }
    }
  }
  if (pr[n - 1] != -1) {
    int p = n - 1;
    while (true) {
      res.push_back(p);
      if (p == 0) {
        break;
      }
      p = pr[p];
    }
    reverse(res.begin(), res.end());
  }
  vector<int> nei0(n, 0);
  for (int x : g[0]) {
    nei0[x] = 1;
  }
  nei0[0] = 1;
  int found = 0;
  for (int x : g[0]) {
    for (int y : g[x]) {
      if (nei0[y] == 0) {
        vector<int> cand = {0, x, y, 0, n - 1};
        if (res.empty() || cand.size() < res.size()) {
          res = cand;
        }
        found = 1;
        break;
      }
    }
    if (found) {
      break;
    }
  }
  if (!found) {
    vector<int> was(n, 0);
    was[0] = 1;
    int v = -1;
    for (int start : g[0]) {
      if (was[start]) {
        continue;
      }
      vector<int> que(1, start);
      was[start] = 1;
      for (int pos = 0; pos < (int) que.size(); pos++) {
        int i = que[pos];
        for (int j : g[i]) {
          if (!was[j]) {
            que.push_back(j);
            was[j] = 1;
          }
        }
      }
      for (int i : que) {
        if (g[i].size() != que.size()) {
          v = i;
          break;
        }
      }
      if (v != -1) {
        break;
      }
    }
    if (v != -1) {
      vector<int> neiv(n, 0);
      for (int x : g[v]) {
        neiv[x] = 1;
      }
      neiv[v] = 1;
      found = 0;
      for (int x : g[v]) {
        if (x == 0) {
          continue;
        }
        for (int y : g[x]) {
          if (neiv[y] == 0) {
            vector<int> cand = {0, v, x, y, v, n - 1};
            if (res.empty() || cand.size() < res.size()) {
              res = cand;
            }
            found = 1;
            break;
          }
        }
        if (found) {
          break;
        }
      }
    }
  }
  if (res.empty()) {
    cout << -1 << '\n';
  } else {
    int sz = (int) res.size();
    cout << sz - 1 << '\n';
    for (int i = 0; i < sz; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << res[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}