/**
 *    author:  tourist
 *    created: 30.01.2022 21:32:30       
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
    vector<int> dist(n, -1);
    vector<int> que(1, 0);
    vector<int> parent(n, -1);
    dist[0] = 0;
    parent[0] = 0;
    for (int b = 0; b < (int) que.size(); b++) {
      for (int u : g[que[b]]) {
        if (dist[u] == -1) {
          que.push_back(u);
          dist[u] = dist[que[b]] + 1;
          parent[u] = que[b];
        }
      }
    }
    const int LOG = 20;
    vector<vector<int>> jump(n, vector<int>(LOG));
    for (int i = 0; i < n; i++) {
      jump[i][0] = parent[i];
    }
    for (int j = 1; j < LOG; j++) {
      for (int i = 0; i < n; i++) {
        jump[i][j] = jump[jump[i][j - 1]][j - 1];
      }
    }
    auto LCA = [&](int u, int v) {
      if (dist[u] < dist[v]) {
        swap(u, v);
      }
      for (int j = LOG - 1; j >= 0; j--) {
        if (dist[u] - (1 << j) >= dist[v]) {
          u = jump[u][j];
        }
      }
      if (u == v) {
        return u;
      }
      for (int j = LOG - 1; j >= 0; j--) {
        if (jump[u][j] != jump[v][j]) {
          u = jump[u][j];
          v = jump[v][j];
        }
      }
      return parent[u];
    };
    auto GetDist = [&](int u, int v) {
      return dist[u] + dist[v] - 2 * dist[LCA(u, v)];
    };
    int x = que.back();
    int y = que.back();
    int d = 0;
    vector<int> res(n + 1, dist[que.back()]);
    for (int b = (int) que.size() - 1; b >= 1; b--) {
      int z = que[b];
      int d_xz = GetDist(x, z);
      int d_yz = GetDist(y, z);
      if (max(d_xz, d_yz) > d) {
        if (d_xz > d_yz) {
          y = z;
          d = d_xz;
        } else {
          x = z;
          d = d_yz;
        }
      }
      int bound = dist[que[b - 1]];
      int rad = (d + 1) / 2;
      // weight + rad <= bound
      int weight = bound - rad;
      if (weight > 0) {
        res[weight] = min(res[weight], bound);
      }
    }
    for (int i = n; i > 1; i--) {
      res[i - 1] = min(res[i - 1], res[i]);
    }
    for (int i = 1; i <= n; i++) {
      cout << res[i] << " \n"[i == n];
    }
  }
  return 0;
}