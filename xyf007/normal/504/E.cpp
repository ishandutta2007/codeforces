#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
constexpr int kB = 1 << 20;
char rbuf[kB + 1], *ps = rbuf + kB, wbuf[kB + 1], *po = wbuf;
char Getchar() {
  if (ps - rbuf == kB) std::cin.read(rbuf, kB), ps = rbuf;
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
  if (po - wbuf == kB) std::cout.write(wbuf, kB), po = wbuf;
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
constexpr long long kBs = 100003LL, kMod = 1019260817LL;
inline long long sub(long long a, long long b) {
  return a >= b ? a - b : a - b + kMod;
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
  int to, nxt;
} e[600001];
int n, q, E, head[300001], sz[300001], fa[300001], dep[300001], son[300001],
    top[300001], len[300001], rk[300001];
long long pw[300001];
char s[300005];
std::vector<int> hd[300001], hu[300001], lk[300001];
void Add(int f, int t) { e[E] = {t, head[f]}, head[f] = E++; }
void Dfs(int u, int f) {
  sz[u] = 1, dep[u] = dep[fa[u] = f] + 1;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == f) continue;
    Dfs(v, u), sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}
void Dfs2(int u, int t) {
  top[u] = t;
  if (son[u]) Dfs2(son[u], t);
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa[u] || v == son[u]) continue;
    Dfs2(v, v);
  }
}
struct Node {
  int x, l, r, op;  // op = 0 -> up, op = 1 -> down
  Node(int x = 0, int l = 0, int r = 0, int op = 0)
      : x(x), l(l), r(r), op(op) {}
};
std::vector<Node> Road(int u, int v) {
  std::vector<Node> l1, l2;
  l1.reserve(40), l2.reserve(20);
  while (top[u] != top[v]) {
    if (dep[top[u]] > dep[top[v]]) {
      l1.emplace_back(top[u], 1, rk[u], 0);
      u = fa[top[u]];
    } else {
      l2.emplace_back(top[v], 1, rk[v], 1);
      v = fa[top[v]];
    }
  }
  if (dep[u] > dep[v])
    l1.emplace_back(top[u], rk[v], rk[u], 0);
  else
    l2.emplace_back(top[u], rk[u], rk[v], 1);
  std::reverse(l2.begin(), l2.end());
  l1.insert(l1.end(), l2.begin(), l2.end());
  return l1;
}
long long Calc(int x, int l, int r, int op) {
  if (op == 0) {
    return sub(hu[x][l], hu[x][r + 1] * pw[r - l + 1] % kMod);
  } else {
    return sub(hd[x][r], hd[x][l - 1] * pw[r - l + 1] % kMod);
  }
}
void Solve(int a, int b, int c, int d) {
  auto r1 = Road(a, b), r2 = Road(c, d);
  std::size_t i1 = 0, i2 = 0;
  int ans = 0;
  while (i1 < r1.size() && i2 < r2.size()) {
    int len = std::min(r1[i1].r - r1[i1].l + 1, r2[i2].r - r2[i2].l + 1), la,
        ra, lb, rb;
    auto mdf = [&](int l) {
      if (r1[i1].op == 0) {
        ra = r1[i1].r, la = ra - l + 1;
      } else {
        la = r1[i1].l, ra = la + l - 1;
      }
      if (r2[i2].op == 0) {
        rb = r2[i2].r, lb = rb - l + 1;
      } else {
        lb = r2[i2].l, rb = lb + l - 1;
      }
    };
    mdf(len);
    if (Calc(r1[i1].x, la, ra, r1[i1].op) ==
        Calc(r2[i2].x, lb, rb, r2[i2].op)) {
      ans += len;
      if (r1[i1].r - r1[i1].l + 1 == len)
        i1++;
      else if (r1[i1].op == 0)
        r1[i1].r -= len;
      else
        r1[i1].l += len;
      if (r2[i2].r - r2[i2].l + 1 == len)
        i2++;
      else if (r2[i2].op == 0)
        r2[i2].r -= len;
      else
        r2[i2].l += len;
      continue;
    }
    int l = 0, r = len, best = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      mdf(mid);
      if (Calc(r1[i1].x, la, ra, r1[i1].op) ==
          Calc(r2[i2].x, lb, rb, r2[i2].op))
        best = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    ans += best;
    break;
  }
  Write(ans, '\n');
}
namespace subtask1 {
bool Check() {
  for (int i = 2; i <= n; i++)
    if (s[i] != s[i - 1]) return false;
  return true;
}
int GetLca(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
    u = fa[top[u]];
  }
  return dep[u] < dep[v] ? u : v;
}
int Dis(int u, int v) { return dep[u] + dep[v] - 2 * dep[GetLca(u, v)]; }
void Solve() {
  Read(q);
  while (q--) {
    int a = Read(), b = Read(), c = Read(), d = Read();
    Write(std::min(Dis(a, b), Dis(c, d)) + 1, '\n');
  }
  std::cout.write(wbuf, po - wbuf);
  std::exit(0);
}
}  // namespace subtask1
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  Read(n), Read(s + 1);
  std::memset(head + 1, -1, 4 * n);
  for (int i = 1; i < n; i++) {
    int u = Read(), v = Read();
    Add(u, v), Add(v, u);
  }
  Dfs(1, 0), Dfs2(1, 1);
  if (subtask1::Check()) subtask1::Solve();
  pw[0] = 1LL;
  for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * kBs % kMod;
  for (int i = 1; i <= n; i++)
    if (top[i] == i) {
      for (int j = i; j; j = son[j]) rk[j] = ++len[i];
      lk[i].resize(len[i] + 1);
      for (int j = i; j; j = son[j]) lk[i][rk[j]] = j;
      hd[i].resize(len[i] + 1);
      hd[i][0] = 1LL;
      for (int j = 1; j <= len[i]; j++)
        hd[i][j] = (hd[i][j - 1] * kBs + s[lk[i][j]]) % kMod;
      hu[i].resize(len[i] + 2);
      hu[i][len[i] + 1] = 1LL;
      for (int j = len[i]; j >= 1; j--)
        hu[i][j] = (hu[i][j + 1] * kBs + s[lk[i][j]]) % kMod;
    }
  Read(q);
  while (q--) {
    int a = Read(), b = Read(), c = Read(), d = Read();
    Solve(a, b, c, d);
  }
  std::cout.write(wbuf, po - wbuf);
  return 0;
}