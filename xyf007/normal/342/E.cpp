#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
constexpr int kInf = 1e9;
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
  int to, nxt;
} e[200001];
int n, q, E, head[100001], c[100001];
std::multiset<int> s[100001];
int Min(int x) { return s[x].empty() ? kInf : *s[x].begin(); }
class LinkCutTree {
 public:
  int lmin_[100001], rmin_[100001];
  LinkCutTree() {}
  void Pushup(int x) {
    sz_[x] = sz_[ch_[x][0]] + sz_[ch_[x][1]] + 1;
    lmin_[x] = std::min(
        lmin_[ch_[x][0]],
        sz_[ch_[x][0]] +
            std::min(c[x] ? 0 : kInf, std::min(lmin_[ch_[x][1]], Min(x)) + 1));
    rmin_[x] = std::min(
        rmin_[ch_[x][1]],
        sz_[ch_[x][1]] +
            std::min(c[x] ? 0 : kInf, std::min(rmin_[ch_[x][0]], Min(x)) + 1));
  }
  void Splay(int x) {
    while (NotRoot(x)) {
      int y = fa_[x];
      if (NotRoot(y)) Rotate(IsRson(x) == IsRson(y) ? y : x);
      Rotate(x);
    }
    Pushup(x);
  }
  void Access(int x) {
    for (int y = 0; x; x = fa_[y = x]) {
      Splay(x);
      s[x].emplace(lmin_[ch_[x][1]]);
      if (auto it = s[x].find(lmin_[y]); it != s[x].end()) s[x].erase(it);
      ch_[x][1] = y;
      Pushup(x);
    }
  }
  void Link(int x, int y) { fa_[x] = y; }
  ~LinkCutTree() {}

 private:
  int ch_[100001][2], fa_[100001], sz_[100001];
  bool NotRoot(int x) { return ch_[fa_[x]][0] == x || ch_[fa_[x]][1] == x; }
  bool IsRson(int x) { return ch_[fa_[x]][1] == x; }
  void Rotate(int x) {
    int y = fa_[x], z = fa_[y], d1 = IsRson(x), d2 = IsRson(y),
        w = ch_[x][d1 ^ 1];
    if (NotRoot(y)) ch_[z][d2] = x;
    ch_[x][d1 ^ 1] = y;
    ch_[y][d1] = w;
    if (w) fa_[w] = y;
    fa_[x] = z;
    fa_[y] = x;
    Pushup(y);
    Pushup(x);
  }
} T;
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
void Dfs(int u, int fa) {
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    T.Link(v, u);
    Dfs(v, u);
  }
}
int main(int argc, char const *argv[]) {
  std::memset(head, -1, sizeof(head));
  Read(n, q);
  for (int i = 1; i < n; i++) {
    int u, v;
    Read(u, v);
    Add(u, v);
    Add(v, u);
  }
  T.lmin_[0] = T.rmin_[0] = kInf;
  Dfs(1, 0);
  T.Access(1);
  T.Splay(1);
  c[1] ^= 1;
  T.Pushup(1);
  while (q--) {
    int op, x;
    Read(op, x);
    T.Access(x);
    T.Splay(x);
    if (op == 1) {
      c[x] ^= 1;
      T.Pushup(x);
    } else {
      std::printf("%d\n", T.rmin_[x] > n ? -1 : T.rmin_[x]);
    }
  }
  return 0;
}