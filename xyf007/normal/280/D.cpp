#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <stack>
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
struct Rec {
  int l, r, v;
  Rec(int l = 0, int r = 0, int v = 0) : l(l), r(r), v(v) {}
  bool operator<(const Rec &rhs) const { return v < rhs.v; }
  Rec operator+(const Rec &rhs) const { return Rec(l, rhs.r, v + rhs.v); }
  ~Rec() {}
};
struct Node {
  Rec min, lmin, rmin, max, lmax, rmax, sum;
} t[400001];
int n, m, a[100001], tag[400001];
Node Merge(Node lhs, Node rhs) {
  Node s;
  s.sum = lhs.sum + rhs.sum;
  s.min = std::min(std::min(lhs.min, rhs.min), lhs.rmin + rhs.lmin);
  s.lmin = std::min(lhs.lmin, lhs.sum + rhs.lmin);
  s.rmin = std::min(rhs.rmin, lhs.rmin + rhs.sum);
  s.max = std::max(std::max(lhs.max, rhs.max), lhs.rmax + rhs.lmax);
  s.lmax = std::max(lhs.lmax, lhs.sum + rhs.lmax);
  s.rmax = std::max(rhs.rmax, lhs.rmax + rhs.sum);
  return s;
}
void Pushup(int x) { t[x] = Merge(t[x + x], t[x + x + 1]); }
void Reverse(int x) {
  std::swap(t[x].min, t[x].max);
  std::swap(t[x].lmin, t[x].lmax);
  std::swap(t[x].rmin, t[x].rmax);
  t[x].sum.v *= -1;
  t[x].min.v *= -1;
  t[x].lmin.v *= -1;
  t[x].rmin.v *= -1;
  t[x].max.v *= -1;
  t[x].lmax.v *= -1;
  t[x].rmax.v *= -1;
}
void Pushdown(int x) {
  if (tag[x]) {
    Reverse(x + x);
    Reverse(x + x + 1);
    tag[x + x] ^= 1;
    tag[x + x + 1] ^= 1;
    tag[x] = 0;
  }
}
void Build(int l, int r, int x) {
  if (l == r) {
    t[x].min = t[x].lmin = t[x].rmin = t[x].max = t[x].lmax = t[x].rmax =
        t[x].sum = Rec(l, l, a[l]);
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x);
  Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify1(int l, int r, int p, int v, int x) {
  if (l == r) {
    t[x].min = t[x].lmin = t[x].rmin = t[x].max = t[x].lmax = t[x].rmax =
        t[x].sum = Rec(l, l, v);
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (p <= mid)
    Modify1(l, mid, p, v, x + x);
  else
    Modify1(mid + 1, r, p, v, x + x + 1);
  Pushup(x);
}
void Modify2(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) {
    Reverse(x);
    tag[x] ^= 1;
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (L <= mid) Modify2(L, R, l, mid, x + x);
  if (R > mid) Modify2(L, R, mid + 1, r, x + x + 1);
  Pushup(x);
}
Node Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) return t[x];
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (R <= mid) return Query(L, R, l, mid, x + x);
  if (L > mid) return Query(L, R, mid + 1, r, x + x + 1);
  return Merge(Query(L, R, l, mid, x + x), Query(L, R, mid + 1, r, x + x + 1));
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  Build(1, n, 1);
  Read(m);
  for (int i = 1; i <= m; i++) {
    int op;
    Read(op);
    if (!op) {
      int p, v;
      Read(p, v);
      Modify1(1, n, p, v, 1);
    } else {
      int l, r, k, ans = 0;
      Read(l, r, k);
      std::stack<std::pair<int, int>> s;
      for (int j = 1; j <= k; j++) {
        Node tmp = Query(l, r, 1, n, 1);
        if (tmp.max.v > 0) {
          ans += tmp.max.v;
          Modify2(tmp.max.l, tmp.max.r, 1, n, 1);
          s.emplace(tmp.max.l, tmp.max.r);
        } else {
          break;
        }
      }
      while (!s.empty()) {
        std::pair<int, int> tmp = s.top();
        s.pop();
        Modify2(tmp.first, tmp.second, 1, n, 1);
      }
      std::printf("%d\n", ans);
    }
  }
  return 0;
}