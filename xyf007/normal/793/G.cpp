#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, q;
std::vector<std::tuple<int, int, int>> a[10005];
namespace maxflow {
struct Edge {
  int to, nxt, cost;
} e[2000001];
int s, t, E, head[1000001], dep[1000001], cur[1000001];
void Add(int f, int t, int c) {
  e[E].to = t, e[E].cost = c, e[E].nxt = head[f];
  head[f] = E++;
}
class SegmentTree {
 private:
  int id_[100001], tot_, cnt_[100001];
  void Pushup(int x) {
    id_[x] = ++tot_;
    if (!cnt_[x + x])
      Add(id_[x], id_[x + x], 0x3f3f3f3f), Add(id_[x + x], id_[x], 0);
    if (!cnt_[x + x + 1])
      Add(id_[x], id_[x + x + 1], 0x3f3f3f3f), Add(id_[x + x + 1], id_[x], 0);
  }

 public:
  SegmentTree(int n) { tot_ = 2 * n; }
  void Build(int l, int r, int x) {
    if (l == r) {
      id_[x] = n + l;
      return;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
    Pushup(x);
  }
  void Modify(int L, int R, int l, int r, int v, int x) {
    if (L <= l && r <= R) {
      cnt_[x] += v;
      return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) Modify(L, R, l, mid, v, x + x);
    if (R > mid) Modify(L, R, mid + 1, r, v, x + x + 1);
    Pushup(x);
  }
  int cnt(int x) { return cnt_[x]; }
  int id(int x) { return id_[x]; }
  int tot() { return tot_; }
  ~SegmentTree() {}
};
void Init() {
  std::memset(head, -1, sizeof(head));
  SegmentTree T(n);
  T.Build(1, n, 1);
  for (int i = 1; i <= n; i++) {
    std::sort(a[i].begin(), a[i].end());
    for (auto &&[op, l, r] : a[i]) T.Modify(l, r, 1, n, op, 1);
    if (!T.cnt(1))
      Add(s, i, 1), Add(i, s, 0), Add(i, T.id(1), 0x3f3f3f3f),
          Add(T.id(1), i, 0);
  }
  t = T.tot() + 1;
  for (int i = 1; i <= n; i++) Add(n + i, t, 1), Add(t, n + i, 0);
}
bool Bfs() {
  std::memset(dep + 1, 0x3f, 4 * t);
  std::memcpy(cur, head, 4 * (t + 1));
  std::queue<int> q;
  q.emplace(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      if (!e[i].cost) continue;
      int v = e[i].to;
      if (dep[u] + 1 < dep[v]) dep[v] = dep[u] + 1, q.emplace(v);
    }
  }
  return dep[t] != 0x3f3f3f3f;
}
int Dfs(int u, int sum) {
  if (u == t || !sum) return sum;
  int ans = 0;
  for (int i = cur[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (e[i].cost && dep[v] == dep[u] + 1) {
      int min = Dfs(v, std::min(sum, e[i].cost));
      ans += min, sum -= min;
      e[i].cost -= min, e[i ^ 1].cost += min;
      if (!sum) break;
    }
    cur[u] = e[i].nxt;
  }
  if (!ans) dep[u] = -1;
  return ans;
}
int maxflow() {
  int ans = 0;
  while (Bfs()) ans += Dfs(s, 0x3f3f3f3f);
  return ans;
}
}  // namespace maxflow
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q;
  while (q--) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    a[x1].emplace_back(1, y1, y2), a[x2 + 1].emplace_back(-1, y1, y2);
  }
  maxflow::Init();
  std::cout << maxflow::maxflow();
  return 0;
}