#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
namespace atcoder {
namespace internal {
template <class E>
struct csr {
  std::vector<int> start;
  std::vector<E> elist;
  explicit csr(int n, const std::vector<std::pair<int, E>> &edges)
      : start(n + 1), elist(edges.size()) {
    for (auto e : edges) start[e.first + 1]++;
    for (int i = 1; i <= n; i++) start[i] += start[i - 1];
    auto counter = start;
    for (auto e : edges) elist[counter[e.first]++] = e.second;
  }
};
}  // namespace internal
}  // namespace atcoder
namespace atcoder {
namespace internal {
template <class T>
struct simple_queue {
  std::vector<T> payload;
  int pos = 0;
  void reserve(int n) { payload.reserve(n); }
  int size() const { return int(payload.size()) - pos; }
  bool empty() const { return pos == int(payload.size()); }
  void push(const T &t) { payload.push_back(t); }
  T &front() { return payload[pos]; }
  void clear() {
    payload.clear();
    pos = 0;
  }
  void pop() { pos++; }
};
}  // namespace internal
}  // namespace atcoder
namespace atcoder {
template <class Cap, class Cost>
struct mcf_graph {
 public:
  mcf_graph() {}
  explicit mcf_graph(int n) : _n(n) {}
  int add_edge(int from, int to, Cap cap, Cost cost) {
    assert(0 <= from && from < _n);
    assert(0 <= to && to < _n);
    assert(0 <= cap);
    assert(0 <= cost);
    int m = int(_edges.size());
    _edges.push_back({from, to, cap, 0, cost});
    return m;
  }
  struct edge {
    int from, to;
    Cap cap, flow;
    Cost cost;
  };
  edge get_edge(int i) {
    int m = int(_edges.size());
    assert(0 <= i && i < m);
    return _edges[i];
  }
  std::vector<edge> edges() { return _edges; }
  std::pair<Cap, Cost> flow(int s, int t) {
    return flow(s, t, std::numeric_limits<Cap>::max());
  }
  std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
    return slope(s, t, flow_limit).back();
  }
  std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
    return slope(s, t, std::numeric_limits<Cap>::max());
  }
  std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);
    assert(s != t);
    int m = int(_edges.size());
    std::vector<int> edge_idx(m);
    auto g = [&]() {
      std::vector<int> degree(_n), redge_idx(m);
      std::vector<std::pair<int, _edge>> elist;
      elist.reserve(2 * m);
      for (int i = 0; i < m; i++) {
        auto e = _edges[i];
        edge_idx[i] = degree[e.from]++;
        redge_idx[i] = degree[e.to]++;
        elist.push_back({e.from, {e.to, -1, e.cap - e.flow, e.cost}});
        elist.push_back({e.to, {e.from, -1, e.flow, -e.cost}});
      }
      auto _g = internal::csr<_edge>(_n, elist);
      for (int i = 0; i < m; i++) {
        auto e = _edges[i];
        edge_idx[i] += _g.start[e.from];
        redge_idx[i] += _g.start[e.to];
        _g.elist[edge_idx[i]].rev = redge_idx[i];
        _g.elist[redge_idx[i]].rev = edge_idx[i];
      }
      return _g;
    }();
    auto result = slope(g, s, t, flow_limit);
    for (int i = 0; i < m; i++) {
      auto e = g.elist[edge_idx[i]];
      _edges[i].flow = _edges[i].cap - e.cap;
    }
    return result;
  }

 private:
  int _n;
  std::vector<edge> _edges;
  struct _edge {
    int to, rev;
    Cap cap;
    Cost cost;
  };
  std::vector<std::pair<Cap, Cost>> slope(internal::csr<_edge> &g, int s, int t,
                                          Cap flow_limit) {
    std::vector<std::pair<Cost, Cost>> dual_dist(_n);
    std::vector<int> prev_e(_n);
    std::vector<bool> vis(_n);
    struct Q {
      Cost key;
      int to;
      bool operator<(Q r) const { return key > r.key; }
    };
    std::vector<int> que_min;
    std::vector<Q> que;
    auto dual_ref = [&]() {
      for (int i = 0; i < _n; i++) {
        dual_dist[i].second = std::numeric_limits<Cost>::max();
      }
      std::fill(vis.begin(), vis.end(), false);
      que_min.clear();
      que.clear();
      size_t heap_r = 0;
      dual_dist[s].second = 0;
      que_min.push_back(s);
      while (!que_min.empty() || !que.empty()) {
        int v;
        if (!que_min.empty()) {
          v = que_min.back();
          que_min.pop_back();
        } else {
          while (heap_r < que.size()) {
            heap_r++;
            std::push_heap(que.begin(), que.begin() + heap_r);
          }
          v = que.front().to;
          std::pop_heap(que.begin(), que.end());
          que.pop_back();
          heap_r--;
        }
        if (vis[v]) continue;
        vis[v] = true;
        if (v == t) break;
        Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;
        for (int i = g.start[v]; i < g.start[v + 1]; i++) {
          auto e = g.elist[i];
          if (!e.cap) continue;
          Cost cost = e.cost - dual_dist[e.to].first + dual_v;
          if (dual_dist[e.to].second - dist_v > cost) {
            Cost dist_to = dist_v + cost;
            dual_dist[e.to].second = dist_to;
            prev_e[e.to] = e.rev;
            if (dist_to == dist_v) {
              que_min.push_back(e.to);
            } else {
              que.push_back(Q{dist_to, e.to});
            }
          }
        }
      }
      if (!vis[t]) {
        return false;
      }
      for (int v = 0; v < _n; v++) {
        if (!vis[v]) continue;
        dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;
      }
      return true;
    };
    Cap flow = 0;
    Cost cost = 0, prev_cost_per_flow = -1;
    std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};
    while (flow < flow_limit) {
      if (!dual_ref()) break;
      Cap c = flow_limit - flow;
      for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
        c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);
      }
      for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
        auto &e = g.elist[prev_e[v]];
        e.cap += c;
        g.elist[e.rev].cap -= c;
      }
      Cost d = -dual_dist[s].first;
      flow += c;
      cost += c * d;
      if (prev_cost_per_flow == d) {
        result.pop_back();
      }
      result.push_back({flow, cost});
      prev_cost_per_flow = d;
    }
    return result;
  }
};
}  // namespace atcoder
#include <iostream>
#include <numeric>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n;
long long a[4401], b[4401], c[4401], rk1[4401], pos1[4401], rk2[4401],
    pos2[4401], cnt[4401];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= 2 * n; i++) std::cin >> a[i] >> b[i];
  std::iota(rk1 + 1, rk1 + 2 * n + 1, 1);
  std::sort(rk1 + 1, rk1 + 2 * n + 1, [](int x, int y) { return b[x] < b[y]; });
  for (int i = 1; i <= 2 * n; i++) pos1[rk1[i]] = i;
  auto check = [](long long mid) {
    for (int i = 1; i <= 2 * n; i++) c[i] = a[i] * mid + b[i];
    std::iota(rk2 + 1, rk2 + 2 * n + 1, 1);
    std::sort(rk2 + 1, rk2 + 2 * n + 1,
              [](int x, int y) { return c[x] < c[y]; });
    for (int i = 1; i <= 2 * n; i++) pos2[rk2[i]] = i;
    std::fill(cnt + 1, cnt + 2 * n + 1, 0);
    for (int l = 1, r, p = 0; l <= 2 * n; l = r + 1) {
      r = l;
      while (r + 1 <= 2 * n && b[rk1[r + 1]] == b[rk1[l]]) r++;
      for (int i = l; i <= r; i++)
        if (pos2[rk1[i]] > pos2[p]) p = rk1[i];
      for (int i = l; i <= r; i++) cnt[pos2[p]] += rk1[i] <= n;
    }
    for (int l = 2 * n, r, s = 0; l >= 1; l = r - 1) {
      r = l;
      while (r - 1 >= 1 && c[rk2[r - 1]] == c[rk2[l]]) r--;
      for (int i = l; i >= r; i--) s += cnt[i];
      for (int i = l; i >= r; i--) s -= rk2[i] > n;
      if (s < 0) return false;
    }
    return true;
  };
  long long l = 0LL, r = 2000000000LL, ans = -1LL;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  if (ans == -1) {
    std::cout << ans;
    return 0;
  }
  check(ans);
  atcoder::mcf_graph<int, int> g(8 * n + 2);
  int s = 0, t = 8 * n + 1, tot = 4 * n;
  for (int i = 1; i <= n; i++) g.add_edge(s, i, 1, 0);
  for (int i = n + 1; i <= 2 * n; i++) g.add_edge(i + 2 * n, t, 1, 0);
  for (int l = 1, r, pre = 0; l <= 2 * n; l = r + 1) {
    int x = ++tot;
    r = l;
    while (r + 1 <= 2 * n && b[rk1[r + 1]] == b[rk1[l]]) r++;
    for (int i = l; i <= r; i++) {
      g.add_edge(rk1[i], x, 0x3f3f3f3f, 1);
      g.add_edge(x, rk1[i], 0x3f3f3f3f, 0);
    }
    if (pre) g.add_edge(x, pre, 0x3f3f3f3f, 0);
    pre = x;
  }
  for (int i = 1; i <= 2 * n; i++) g.add_edge(i, i + 2 * n, 0x3f3f3f3f, 0);
  for (int l = 1, r, pre = 0; l <= 2 * n; l = r + 1) {
    int x = ++tot;
    r = l;
    while (r + 1 <= 2 * n && c[rk2[r + 1]] == c[rk2[l]]) r++;
    for (int i = l; i <= r; i++) {
      g.add_edge(rk2[i] + 2 * n, x, 0x3f3f3f3f, 1);
      g.add_edge(x, rk2[i] + 2 * n, 0x3f3f3f3f, 0);
    }
    if (pre) g.add_edge(x, pre, 0x3f3f3f3f, 0);
    pre = x;
  }
  std::cout << ans << ' ' << g.flow(s, t).second;
  return 0;
}