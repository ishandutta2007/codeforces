#include <algorithm>
#include <cstdio>
#include <numeric>
#include <set>
#include <vector>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
char rbuf[1 << 20], *ps, *pt, wbuf[1 << 20], *po = wbuf;
char Getchar() {
  if (ps == pt) {
    pt = (ps = rbuf) + std::fread(rbuf, 1, 1 << 20, stdin);
    if (ps == pt) return EOF;
  }
  return *ps++;
}
template <typename T = int>
T Read() {
  T x = 0;
  int f = 1;
  char c;
  while ((c = Getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  return x * f;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
void Read(char &c) { c = Getchar(); }
void Read(char *s) {
  char c = Getchar();
  while (c <= 32) c = Getchar();
  while (c > 32) *s++ = c, c = Getchar();
  *s = '\0';
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x), Read(args...);
}
void Putchar(const char &c) {
  if (po - wbuf == 1 << 20) std::fwrite(wbuf, po - wbuf, 1, stdout), po = wbuf;
  *po++ = c;
}
template <typename T>
void Write(const T &x) {
  if (x < 0) {
    Putchar('-'), Write(-x);
    return;
  }
  if (x > 9) Write(x / 10);
  Putchar(x % 10 + '0');
}
void Write(const char c) { Putchar(c); }
void Write(const char *s) {
  while (*s != '\0') Putchar(*s++);
}
template <typename T, typename... Args>
void Write(const T &x, const Args &...args) {
  Write(x), Write(args...);
}
class AutoFlusher {
 public:
  AutoFlusher() {}
  ~AutoFlusher() { std::fwrite(wbuf, po - wbuf, 1, stdout); }
} autoflusher;
struct Op {
  int op, x;
} b[500001];
struct Edge {
  int u, v;
} e[300001];
int n, m, q, a[200001], fa[500001], son[500001], rt[500001];
bool vis[300001];
std::set<int, std::greater<int>> s[200001];
std::vector<int> d[500001];
class DisjointSet {
 public:
  DisjointSet() {}
  void Init(int n) {
    std::iota(fa_ + 1, fa_ + n + 1, 1), std::fill(sz_ + 1, sz_ + n + 1, 1);
  }
  int Find(int x) { return fa_[x] == x ? x : fa_[x] = Find(fa_[x]); }
  bool Merge(int x, int y, int t = 0) {
    int fx = Find(x), fy = Find(y);
    if (fx == fy) return false;
    if (sz_[fx] < sz_[fy]) std::swap(fx, fy);
    auto it = s[fx].end();
    while (!s[fy].empty()) {
      d[t].push_back(*s[fy].begin());
      it = s[fx].emplace_hint(it, *s[fy].begin());
      s[fy].erase(s[fy].begin());
    }
    fa_[fy] = fx, sz_[fx] += sz_[fy];
    fa[t] = fx, son[t] = fy;
    return true;
  }
  ~DisjointSet() {}

 private:
  int fa_[200001], sz_[200001];
} dsu;
int main(int argc, char const *argv[]) {
  Read(n, m, q), dsu.Init(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  for (int i = 1; i <= n; i++) s[i].emplace(a[i]);
  for (int i = 1; i <= m; i++) Read(e[i].u, e[i].v);
  for (int i = 1; i <= q; i++) {
    Read(b[i].op, b[i].x);
    if (b[i].op == 2) vis[b[i].x] = true;
  }
  for (int i = 1; i <= m; i++)
    if (!vis[i]) dsu.Merge(e[i].u, e[i].v);
  for (int i = q; i >= 1; i--)
    if (b[i].op == 1)
      rt[i] = dsu.Find(b[i].x);
    else
      dsu.Merge(e[b[i].x].u, e[b[i].x].v, i);
  for (int i = 1; i <= q; i++)
    if (b[i].op == 1) {
      if (s[rt[i]].empty()) {
        Write("0\n");
      } else {
        Write(*s[rt[i]].begin(), '\n');
        s[rt[i]].erase(s[rt[i]].begin());
      }
    } else {
      auto it = s[son[i]].end();
      for (const auto &x : d[i])
        if (s[fa[i]].count(x))
          s[fa[i]].erase(x), it = s[son[i]].emplace_hint(it, x);
    }
  return 0;
}