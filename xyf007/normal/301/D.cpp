#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
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
struct Query {
  int l, r, id;
} b[200001];
int n, m, a[200001], pos[200001], ans[200001];
std::vector<int> v[200001];
class FenwickTree {
 public:
  FenwickTree() {}
  void Add(int x) {
    while (x <= n) {
      t_[x]++;
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
  int t_[200001];
} T;
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= n; i++) {
    Read(a[i]);
    pos[a[i]] = i;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i) {
      int l = pos[i], r = pos[j];
      if (l > r) std::swap(l, r);
      v[r].emplace_back(l);
    }
  for (int i = 1; i <= m; i++) {
    Read(b[i].l, b[i].r);
    b[i].id = i;
  }
  std::sort(b + 1, b + m + 1, [](const Query &lhs, const Query &rhs) -> bool {
    return lhs.r < rhs.r;
  });
  int p = 1;
  for (int i = 1; i <= m; i++) {
    while (p <= b[i].r) {
      for (auto &&j : v[p]) T.Add(j);
      p++;
    }
    ans[b[i].id] = T.Query(b[i].r) - T.Query(b[i].l - 1);
  }
  for (int i = 1; i <= m; i++) std::printf("%d\n", ans[i]);
  return 0;
}