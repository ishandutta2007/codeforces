#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
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
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + (c - '0');
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &... args) {
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
int n, q, a[150001], tot, id[1000002], col[100001], c[150001];
bool not_prime[1000002];
std::vector<int> d[1000002];
class DisjointSet {
 public:
  DisjointSet() {}
  void Init(int n) { std::iota(fa_ + 1, fa_ + n + 1, 1); }
  int Find(int x) { return fa_[x] == x ? x : fa_[x] = Find(fa_[x]); }
  bool Merge(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if (fx == fy) return false;
    fa_[fx] = fy;
    return true;
  }
  ~DisjointSet() {}

 private:
  int fa_[100001];
} T;
void Init(int n) {
  not_prime[1] = true;
  for (int i = 2; i <= n; i++)
    if (!not_prime[i]) {
      id[i] = ++tot;
      for (int j = i; j <= n; j += i)
        d[j].emplace_back(tot), not_prime[j] = true;
    }
  T.Init(tot);
}
int main(int argc, char const *argv[]) {
  Init(1000001);
  Read(n, q);
  for (int i = 1; i <= n; i++) Read(a[i]);
  for (int i = 1; i <= n; i++) {
    int u = d[a[i]].front();
    for (std::size_t j = 1; j < d[a[i]].size(); j++) T.Merge(u, d[a[i]][j]);
  }
  for (int i = 1; i <= tot; i++) col[i] = T.Find(i);
  std::vector<int> tmp;
  std::set<std::pair<int, int>> s;
  for (int i = 1; i <= n; i++) {
    c[i] = col[d[a[i]].front()];
    for (auto &&g : d[a[i] + 1]) tmp.emplace_back(col[g]);
    for (auto &&g : d[a[i]]) tmp.emplace_back(col[g]);
    std::sort(tmp.begin(), tmp.end());
    tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
    for (std::size_t j = 0; j + 1 < tmp.size(); j++)
      for (std::size_t k = j + 1; k < tmp.size(); k++)
        s.emplace(tmp[j], tmp[k]);
    std::vector<int>().swap(tmp);
  }
  while (q--) {
    int u, v;
    Read(u, v);
    if (c[u] == c[v])
      std::printf("0\n");
    else if (s.count({std::min(c[u], c[v]), std::max(c[u], c[v])}))
      std::printf("1\n");
    else
      std::printf("2\n");
  }
  return 0;
}