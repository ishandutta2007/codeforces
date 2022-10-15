#include <bits/stdc++.h>

template <typename T>
struct Dinic {
  inline static const T inf = std::numeric_limits<T>::max();
  struct Edge {
    int from, to;
    T cap, flow = 0;
    T free() const {
      return cap - flow;
    }
    Edge(int u, int v, T cap) : from(u), to(v), cap(cap) {}
  };
  std::vector<Edge> edges;
  int N, M = 0;
  std::vector<std::vector<int>> E;
  std::vector<int> level, ptr;
  Dinic(int N) : N(N), E(N), level(N), ptr(N) {}
  int add_edge(int u, int v, T cap) {
    assert(cap >= 0);
    edges.emplace_back(u, v, cap);
    edges.emplace_back(v, u, 0);
    E[u].push_back(M++);
    E[v].push_back(M++);
    return M - 2;
  }
  bool bfs(int s, int t) {
    std::fill(level.begin(), level.end(), -1);
    level[s] = 0;
    static std::queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto j : E[u]) {
        int v = edges[j].to;
        if (level[v] != -1 || edges[j].free() <= 0) continue;
        level[v] = level[u] + 1;
        q.push(v);
      }
    }
    return level[t] != -1;
  }
  T push(int u, int t, T pushed) {
    if (u == t || pushed == 0) return pushed;
    for (int& i = ptr[u]; i < E[u].size(); ++i) {
      auto &edge = edges[E[u][i]], &back = edges[E[u][i] ^ 1];
      if (level[edge.to] != level[u] + 1 || edge.free() <= 0) continue;
      T pushing = push(edge.to, t, std::min(pushed, edge.free()));
      if (pushing == 0) continue;
      edge.flow += pushing, back.flow -= pushing;
      return pushing;
    }
    return 0;
  }
  T f = 0;
  T flow(int s, int t) {
    while (bfs(s, t)) {
      std::fill(ptr.begin(), ptr.end(), 0);
      while (T pushed = push(s, t, inf)) f += pushed;
    }
    return f;
  }
  bool cut(int j) const {
    return edges[j].free() == 0 && level[edges[j].from] != -1 &&
           level[edges[j].to] == -1;
  }
};

std::pair<std::vector<int>, std::vector<int>> sieve(int N) {
  std::vector<int> lp(N + 1), pr;
  for (int i = 2; i <= N; ++i) {
    if (lp[i] == 0) {
      pr.push_back(lp[i] = i);
    }
    for (auto p : pr) {
      if (p > lp[i] || i * p > N) break;
      lp[i * p] = p;
    }
  }
  return {lp, pr};
}
  
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, K;
  std::cin >> N >> K;
  std::vector<int> p(N), c(N), l(N), ones = {-1};
  for (int i = 0; i < N; ++i) {
    std::cin >> p[i] >> c[i] >> l[i];
    if (c[i] == 1) {
      ones.push_back(i);
    }
  }
  auto pr = sieve(2 * *std::max_element(c.begin(), c.end())).second;
  std::vector<int> I(N);
  std::iota(I.begin(), I.end(), 0);
  std::sort(I.begin(), I.end(), [&](int i, int j) { return l[i] < l[j]; });
  int ans = -1;
  for (auto o : ones) {
    Dinic<int> dinic(N + 2);
    int s = N, t = N + 1;
    int sum = 0;
    for (auto i : I) {
      if (c[i] == 1 && i != o) continue;
      for (auto j : I) {
        if (j == i) break;
        if (std::binary_search(pr.begin(), pr.end(), c[i] + c[j])) {
          if (c[i] % 2) {
            dinic.add_edge(i, j, Dinic<int>::inf);
          } else {
            dinic.add_edge(j, i, Dinic<int>::inf);
          }
        }
      }
      if (c[i] % 2) {
        dinic.add_edge(s, i, p[i]);
      } else {
        dinic.add_edge(i, t, p[i]);
      }
      sum += p[i];
      int alpha = sum - dinic.flow(s, t);
      if (alpha >= K) {
        if (ans == -1) {
          ans = l[i];
        } else {
          ans = std::min(ans, l[i]);
        }
        break;
      }
    }
  }
  std::cout << ans << '\n';
  exit(0);
}