#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
struct Node {
  int l, r, id;
  bool z;
} b[100001];
struct Edge {
  int to, nxt;
} e[100001];
int n, m, E, head[100001], a[100001], cnt, dep[100001], in[100001], out[100001],
    tot, c[100001], pos[100001], ans[100001], pre[100001];
std::vector<int> v[100001], v2[100001];
std::unordered_map<std::string, int> mp;
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
void Dfs(int u) {
  v[dep[u]].emplace_back(in[u] = ++tot);
  v2[dep[u]].emplace_back(u);
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    dep[v] = dep[u] + 1;
    Dfs(v);
  }
  out[u] = tot;
}
class FenwickTree {
 public:
  FenwickTree() {}
  void Add(int x, int v) {
    while (x <= n) {
      t_[x] += v;
      x += x & -x;
    }
  }
  int Query(int x) {
    int s = 0;
    while (x) {
      s += t_[x];
      x -= x & -x;
    }
    return s;
  }
  ~FenwickTree() {}

 private:
  int t_[100001];
} T;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::memset(head, -1, sizeof(head));
  std::cin >> n;
  std::string s;
  int f;
  for (int i = 1; i <= n; i++) {
    std::cin >> s >> f;
    if (!mp.count(s)) {
      mp[s] = ++cnt;
    }
    a[i] = mp[s];
    Add(f, i);
  }
  Dfs(0);
  int now = 0;
  for (int i = 1; i <= n; i++) {
    for (auto &&j : v2[i]) {
      c[pos[j] = ++now] = a[j];
    }
  }
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, k, d, l, r;
    std::cin >> x >> k;
    d = dep[x] + k;
    l = std::lower_bound(v[d].begin(), v[d].end(), in[x]) - v[d].begin();
    r = std::upper_bound(v[d].begin(), v[d].end(), out[x]) - v[d].begin() - 1;
    if (l <= r) {
      b[i].l = pos[v2[d][l]];
      b[i].r = pos[v2[d][r]];
      b[i].id = i;
    } else {
      b[i].z = true;
    }
  }
  std::sort(b + 1, b + m + 1, [](const Node &lhs, const Node &rhs) -> bool {
    return lhs.r < rhs.r;
  });
  now = 0;
  for (int i = 1; i <= m; i++) {
    if (b[i].z) {
      continue;
    }
    while (now < b[i].r) {
      now++;
      if (pre[c[now]]) {
        T.Add(pre[c[now]], -1);
      }
      T.Add(pre[c[now]] = now, 1);
    }
    ans[b[i].id] = T.Query(b[i].r) - T.Query(b[i].l - 1);
  }
  for (int i = 1; i <= m; i++) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}