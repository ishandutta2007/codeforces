#include <bits/stdc++.h>

struct EulerianTour {
  int N, M = 0, odd = 0;
  std::vector<std::vector<std::pair<int, int>>> E;
  std::vector<int> deg;
  std::vector<bool> vis;
  EulerianTour(int N) : N(N), E(N), deg(N), vis(N) {}
  void add_edge(int u, int v) {
    int V[2] = {u, v};
    for (auto t : {0, 1}) {
      int v = V[t];
      E[v].emplace_back(V[t ^ 1], M << 1 | t);
      deg[v] += 1;
      odd += (deg[v] % 2 ? +1 : -1);
    }
    ++M;
  }
  // returns eulerian tour by vertices and edges (reversed if first bit is 1)
  std::pair<std::vector<int>, std::vector<int>> find(int src) {
    assert(odd == 0);
    auto d = deg;
    std::vector<bool> dead(M, false);
    std::vector<int> ptr(N, 0), p, e;
    std::stack<std::pair<int, int>> stk;
    stk.emplace(src, -1);
    while (!stk.empty()) {
      auto [u, i] = stk.top();
      vis[u] = true;
      if (d[u] == 0) {
        stk.pop();
        p.push_back(u);
        if (i != -1) e.push_back(i);
      } else {
        for (int& l = ptr[u]; l < deg[u]; ++l) {
          auto [v, j] = E[u][l];
          if (!dead[j >> 1]) {
            stk.emplace(v, j);
            --d[u], --d[v], dead[j >> 1] = true;
            break;
          }
        }
      }
    }
    return {p, e};
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int M;
  std::cin >> M;
  std::vector<std::vector<int>> a(M);
  std::vector<int> N(M), values;
  for (int j = 0; j < M; ++j) {
    std::cin >> N[j];
    a[j].resize(N[j]);
    for (auto& x : a[j]) {
      std::cin >> x;
      values.push_back(x);
    }
  }
  std::sort(values.begin(), values.end());
  values.erase(std::unique(values.begin(), values.end()), values.end());
  int K = values.size();
  EulerianTour et(M + K);
  std::vector<std::pair<int, int>> coords;
  for (int j = 0; j < M; ++j) {
    for (int i = 0; i < N[j]; ++i) {
      int x = std::lower_bound(values.begin(), values.end(), a[j][i]) - values.begin();
      et.add_edge(j, M + x);
      coords.emplace_back(j, i);
    }
  }
  if (et.odd) {
    std::cout << "NO\n";
  } else {
    std::vector<int> e;
    for (int u = 0; u < M + K; ++u) {
      if (!et.vis[u]) {
        auto f = et.find(u).second;
        e.insert(e.end(), f.begin(), f.end());
      }
    }
    std::vector<std::string> res(M);
    for (int j = 0; j < M; ++j) {
      res[j].resize(N[j]);
    }
    for (auto l : e) {
      int id = l >> 1;
      res[coords[id].first][coords[id].second] = l & 1 ? 'L' : 'R';
    }
    std::cout << "YES\n";
    for (int j = 0; j < M; ++j) {
      std::cout << res[j] << '\n';
    }
  }
  exit(0);
}