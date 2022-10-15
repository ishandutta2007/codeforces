#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Edge {
  int u, v, c;
} e[200001];
int n, m;
long long k;
std::vector<int> g[200001];
std::set<int> ud;
class DisjointSet {
 public:
  DisjointSet() {}
  void set_n(int n) { n_ = n; }
  void Init() { std::iota(fa_ + 1, fa_ + n_ + 1, 1); }
  int Find(int x) {
    if (x == fa_[x]) return x;
    return fa_[x] = Find(fa_[x]);
  }
  int get_fa(int x) { return fa_[x]; }
  bool Merge(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if (fx == fy) return false;
    fa_[fx] = fy;
    return true;
  }
  ~DisjointSet() {}

 private:
  int n_, fa_[200001];
} ori, inv;
void Dfs(int u) {
  ud.erase(u);
  for (int v = 0; v <= n; v++) {
    auto it = ud.lower_bound(v);
    if (it == ud.end()) return;
    v = *it;
    if (!std::binary_search(g[u].begin(), g[u].end(), v)) {
      inv.Merge(u, v);
      k--;
      Dfs(v);
    }
  }
}
int main(int argc, char const *argv[]) {
  Read(n, m);
  k = n * static_cast<long long>(n - 1) / 2 - m;
  ori.set_n(n);
  inv.set_n(n);
  ori.Init();
  inv.Init();
  for (int i = 1; i <= n; i++) ud.emplace(i);
  int w = 0;
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    Read(u, v, c);
    w ^= c;
    e[i] = (Edge){u, v, c};
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  for (int i = 1; i <= n; i++) std::sort(g[i].begin(), g[i].end());
  for (int i = 1; i <= n; i++)
    if (ud.count(i)) Dfs(i);
  if (k > 0) w = 0;
  std::sort(e + 1, e + m + 1, [](const Edge &lhs, const Edge &rhs) -> bool {
    return lhs.c < rhs.c;
  });
  int ans = 0;
  for (int i = 1; i <= m; i++)
    if (inv.Merge(e[i].u, e[i].v)) {
      ans += e[i].c;
      ori.Merge(e[i].u, e[i].v);
    } else if (ori.Merge(e[i].u, e[i].v)) {
      checkmin(w, e[i].c);
    }
  std::printf("%d", ans + w);
  return 0;
}