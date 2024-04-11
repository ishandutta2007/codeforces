#include <bits/stdc++.h>
using namespace std;

template <class CapType = int>
struct MaxFlow {
  struct Edge {
    size_t to, rev;
    CapType cap, flow;
    Edge(size_t to, CapType cap, size_t rev)
        : to(to), cap(cap), rev(rev), flow(0) {}
  };
  vector<vector<Edge>> g;
  vector<size_t> iter;
  vector<int> lev;
  size_t num_node;

  MaxFlow() = default;
  MaxFlow(size_t n) : num_node(n), g(n), lev(n, 0), iter(n, 0) {}

  void AddEdge(size_t u, size_t v, CapType cap) {
    g[u].emplace_back(v, cap, g[v].size() - 0);
    g[v].emplace_back(u, 0, g[u].size() - 1);
  }

  bool Bfs(size_t src, size_t snk) {
    fill(lev.begin(), lev.end(), -1);
    lev[src] = 0;
    vector<size_t> que(1, src);
    for (size_t it = 0; it < que.size(); ++it) {
      size_t x = que[it];
      for (const Edge &e : g[x]) {
        if (e.cap == 0) continue;
        if (lev[e.to] == -1) {
          lev[e.to] = lev[x] + 1;
          que.push_back(e.to);
        }
      }
    }
    return lev[snk] != -1;
  }

  CapType Flow(size_t x, size_t snk, CapType flow) {
    if (x == snk) return flow;
    CapType res = 0;
    for (size_t &it = iter[x]; it < g[x].size(); it++) {
      Edge &e = g[x][it];
      if (e.cap == 0) continue;
      if (lev[e.to] != lev[x] + 1) continue;
      CapType f = Flow(e.to, snk, min(e.cap, flow));
      res += f;
      flow -= f;
      e.cap -= f;
      e.flow += f;
      g[e.to][e.rev].cap += f;
      g[e.to][e.rev].flow -= f;
      if (!flow) break;
    }
    if (!res) lev[x] = -1;
    return res;
  }

  CapType operator()(size_t src, size_t snk) {
    constexpr CapType kInf = numeric_limits<CapType>::max();
    CapType res = 0;
    while (Bfs(src, snk)) {
      fill(iter.begin(), iter.end(), 0);
      res += Flow(src, snk, kInf);
    }
    return res;
  }

  CapType GetResidual(size_t from, size_t to) const {
    for (const Edge &e : g[from]) {
      if (e.to == to) return e.cap;
    }
    return -1;
  }

  CapType GetFlow(size_t from, size_t to) const {
    for (const Edge &e : g[from]) {
      if (e.to == to) return e.flow;
    }
    return -1;
  }

  pair<CapType, vector<size_t>> MinCut(size_t src, size_t snk) {
    CapType cut = operator()(src, snk); 
    vector<size_t> que = {src};
    vector<bool> vis(num_node);
    vis[src] = true;
    for (size_t it = 0; it < que.size(); ++it) {
      size_t x = que[it];
      for (const Edge& e : g[x]) {
        if (e.cap > 0) {
          if (!vis[e.to]) {
            vis[e.to] = true;
            que.push_back(e.to);
          }
        }
      }
    }
    return make_pair(cut, que);
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  int a, b;
  cin >> a >> b;
  a--;
  b--;
  MaxFlow<int64_t> fg(2 * N + 2);
  fg.AddEdge(N + N, a, 1'000'000'000'000'000'000);
  fg.AddEdge(N + N, b + N, 1'000'000'000'000'000'000);
  fg.AddEdge(a + N, N + N + 1, 1'000'000'000'000'000'000);
  fg.AddEdge(b, N + N + 1, 1'000'000'000'000'000'000);
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    fg.AddEdge(u, v + N, w);
    fg.AddEdge(v + N, u, w);
    fg.AddEdge(v, u + N, w);
    fg.AddEdge(u + N, v, w);
  }
  auto [flow, cut] = fg.MinCut(N + N, N + N + 1);
  cout << flow << "\n";
  std::vector<bool> cuts(N + N);
  for (int u : cut) {
    cuts[u] = true;
  }
  for (int i = 0; i < N; ++i) {
    if (cuts[i] && !cuts[i + N]) cout << "A";
    else if (cuts[i + N] && !cuts[i]) cout << "B";
    else cout << "C";
  }
  cout << "\n";
  return 0;
}