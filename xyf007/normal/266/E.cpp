#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
constexpr int kMod = 1e9 + 7;
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) {
      return EOF;
    }
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9') {
    if (c == '-') {
      f = -1;
    }
  }
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') {
    x = x * 10 + c - '0';
  }
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) {
    x = y;
  }
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) {
    x = y;
  }
}
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
int n, m, a[100001], pw[100001][6], spw[100001][6], tag[400001], C[6][6];
class Node {
 public:
  Node() { std::memset(s_, 0, sizeof(s_)); }
  int &operator[](const int &lhs) { return s_[lhs]; }
  int operator[](const int &lhs) const { return s_[lhs]; }
  Node operator+(const Node &rhs) const {
    Node ans;
    for (int i = 0; i <= 5; i++) {
      ans[i] = add(s_[i], rhs[i]);
    }
    return ans;
  }
  Node &operator+=(const Node &rhs) { return *this = *this + rhs; }

 private:
  int s_[6];
} sum[400001];
void Pushup(int x) { sum[x] = sum[x + x] + sum[x + x + 1]; }
void Cover(int l, int r, int x, int v) {
  for (int i = 0; i <= 5; i++) {
    sum[x][i] = mul(v, sub(spw[r][i], spw[l - 1][i]));
  }
  tag[x] = v;
}
void Pushdown(int l, int r, int x) {
  if (~tag[x]) {
    int mid = (l + r) >> 1;
    Cover(l, mid, x + x, tag[x]);
    Cover(mid + 1, r, x + x + 1, tag[x]);
    tag[x] = -1;
  }
}
void Build(int l, int r, int x) {
  if (l == r) {
    for (int i = 0; i <= 5; i++) {
      sum[x][i] = mul(a[l], pw[l][i]);
    }
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x);
  Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify(int L, int R, int l, int r, int v, int x) {
  if (L <= l && r <= R) {
    Cover(l, r, x, v);
    return;
  }
  Pushdown(l, r, x);
  int mid = (l + r) >> 1;
  if (L <= mid) {
    Modify(L, R, l, mid, v, x + x);
  }
  if (R > mid) {
    Modify(L, R, mid + 1, r, v, x + x + 1);
  }
  Pushup(x);
}
Node Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) {
    return sum[x];
  }
  Pushdown(l, r, x);
  int mid = (l + r) >> 1;
  Node ans;
  if (L <= mid) {
    ans += Query(L, R, l, mid, x + x);
  }
  if (R > mid) {
    ans += Query(L, R, mid + 1, r, x + x + 1);
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= n; i++) {
    Read(a[i]);
  }
  for (int i = 0; i <= n; i++) {
    pw[i][0] = spw[i][0] = 1;
    for (int j = 1; j <= 5; j++) {
      pw[i][j] = mul(pw[i][j - 1], i);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 5; j++) {
      spw[i][j] = add(spw[i - 1][j], pw[i][j]);
    }
  }
  C[0][0] = 1;
  for (int i = 1; i <= 5; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
    }
  }
  Build(1, n, 1);
  std::memset(tag, -1, sizeof(tag));
  for (int i = 1; i <= m; i++) {
    char op = Gc();
    int l, r, x;
    while (op != '?' && op != '=') {
      op = Gc();
    }
    Read(l, r, x);
    if (op == '=') {
      Modify(l, r, 1, n, x, 1);
    } else {
      Node t = Query(l, r, 1, n, 1);
      int p[6], tt = sub(1, l), ans = 0;
      p[0] = 1;
      for (int i = 1; i <= x; i++) {
        p[i] = mul(p[i - 1], tt);
      }
      for (int i = 0; i <= x; i++) {
        Add(ans, mul(C[x][i], p[x - i], t[i]));
      }
      std::printf("%d\n", ans);
    }
  }
  return 0;
}