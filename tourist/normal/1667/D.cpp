/**
 *    author:  tourist
 *    created: 19.04.2022 19:14:55       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
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
    vector<vector<vector<int>>> children(n, vector<vector<int>>(2));
    vector<int> pv(n, -1);
    vector<int> pc(n, -1);
    bool fail = false;
    function<void(int)> Dfs = [&](int v) {
      int bal = 0;
      for (int u : g[v]) {
        if (u == pv[v]) {
          continue;
        }
        pv[u] = v;
        Dfs(u);
        children[v][pc[u]].push_back(u);
        if (pc[u] == 1) {
          bal += 1;
        } else {
          bal -= 1;
        }
      }
      if (v > 0) {
        if (bal <= 0) {
          pc[v] = 1;
          bal += 1;
        } else {
          pc[v] = 0;
          bal -= 1;
        }
      }
      if (bal < 0 || bal > 1) {
        fail = true;
      }
    };
    Dfs(0);
    if (fail) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    vector<int> mark(n);
    for (int i = 0; i < n; i++) {
      mark[i] = (int) g[i].size() % 2;
    }
    function<void(int)> Build = [&](int v) {
      while (true) {
        if (children[v][mark[v]].empty()) {
          break;
        }
        vector<int> seq(1, v);
        int x = v;
        while (true) {
          assert(!children[x][mark[x]].empty());
          int y = children[x][mark[x]].back();
          children[x][mark[x]].pop_back();
          seq.push_back(y);
          if (mark[y] == mark[x]) {
            break;
          }
          x = y;
        }
        for (int i = (int) seq.size() - 1; i > 0; i--) {
          cout << seq[i] + 1 << " " << seq[i - 1] + 1 << '\n';
          mark[seq[i]] ^= 1;
          mark[seq[i - 1]] ^= 1;
        }
        for (int i = (int) seq.size() - 1; i > 0; i--) {
          Build(seq[i]);
        }
      }
    };
    Build(0);
  }
  return 0;
}