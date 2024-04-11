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
struct Node {
  std::pair<long long, int> e[3];
  Node() { e[0] = e[1] = e[2] = {1e18, 0}; }
} t[400001], min[100001];
Node Merge(Node lhs, Node rhs) {
  Node ans = lhs;
  for (auto &&v : rhs.e) {
    if (v.first < ans.e[0].first) std::swap(v, ans.e[0]);
    if ((v.first < ans.e[1].first && v.second != ans.e[0].second) ||
        ans.e[0].second == ans.e[1].second)
      std::swap(v, ans.e[1]);
    if ((v.first < ans.e[2].first && v.second != ans.e[0].second &&
         v.second != ans.e[1].second) ||
        (ans.e[0].second == ans.e[2].second ||
         ans.e[1].second == ans.e[2].second))
      std::swap(v, ans.e[2]);
  }
  return ans;
}
void Pushup(int x) { t[x] = Merge(t[x + x], t[x + x + 1]); }
void Modify(int l, int r, int p, const Node &v, int x) {
  if (l == r) {
    t[x] = v;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    Modify(l, mid, p, v, x + x);
  else
    Modify(mid + 1, r, p, v, x + x + 1);
  Pushup(x);
}
int n, m, q;
std::set<std::tuple<long long, int, int>> E, E2;
std::set<std::pair<long long, int>> g[100001];
std::multiset<long long> s;
void Insert(int x) {
  auto it = g[x].begin();
  for (int i = 0; i < 3; i++) min[x].e[i] = *it++;
  long long sum = min[x].e[0].first + min[x].e[1].first + min[x].e[2].first;
  s.emplace(sum);
  Modify(1, n, x, min[x], 1);
}
void Erase(int x) {
  long long sum = min[x].e[0].first + min[x].e[1].first + min[x].e[2].first;
  s.erase(s.find(sum));
}
long long Query() {
  long long ans = 1e18;
  if (!s.empty()) ans = *s.begin();
  auto [w, u, v] = *E2.begin();
  Modify(1, n, u, min[0], 1), Modify(1, n, v, min[0], 1);
  for (auto &&[ww, vv] : t[1].e)
    if (vv != u && vv != v) checkmin(ans, ww + w);
  Modify(1, n, u, min[u], 1), Modify(1, n, v, min[v], 1);
  for (auto &&[w1, v1] : min[u].e)
    for (auto &&[w2, v2] : min[v].e)
      if (v1 != v && v2 != u && v1 != v2) checkmin(ans, w1 + w2);
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++)
    g[i].emplace(1e18, 0), g[i].emplace(2e18, 0), g[i].emplace(3e18, 0);
  for (int i = 1; i <= m; i++) {
    int u, v;
    long long w;
    std::cin >> u >> v >> w;
    if (u > v) std::swap(u, v);
    g[u].emplace(w, v), g[v].emplace(w, u);
    E.emplace(u, v, w), E2.emplace(w, u, v);
  }
  for (int i = 1; i <= n; i++) Insert(i);
  std::cout << Query() << '\n';
  std::cin >> q;
  while (q--) {
    int op, u, v, w;
    std::cin >> op >> u >> v;
    if (u > v) std::swap(u, v);
    if (!op) {
      auto it = E.lower_bound({u, v, -1e9});
      w = std::get<2>(*it);
      g[u].erase({w, v}), g[v].erase({w, u});
      E.erase(it), E2.erase({w, u, v});
      Erase(u), Erase(v);
      Insert(u), Insert(v);
    } else {
      std::cin >> w;
      g[u].emplace(w, v), g[v].emplace(w, u);
      E.emplace(u, v, w), E2.emplace(w, u, v);
      Erase(u), Erase(v);
      Insert(u), Insert(v);
    }
    std::cout << Query() << '\n';
  }
  return 0;
}