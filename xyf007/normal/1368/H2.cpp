#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <cctype>
#include <cstring>
#include <iostream>
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
  while (!std::isdigit(c = Getchar()))
    if (c == '-') f = -1;
  x = c - '0';
  while (std::isdigit(c = Getchar())) x = x * 10 + c - '0';
  return x * f;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while (!std::isdigit(c = Getchar()))
    if (c == '-') f = -1;
  x = c - '0';
  while (std::isdigit(c = Getchar())) x = x * 10 + c - '0';
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
using std::literals::string_literals::operator""s;
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
class Matrix {
 public:
  Matrix() { std::memset(a_, 0x3f, sizeof(a_)); }
  int *operator[](std::size_t x) { return a_[x]; }
  const int *operator[](std::size_t x) const { return a_[x]; }
  Matrix operator*(const Matrix &rhs) const {
    Matrix s;
    for (std::size_t i = 0; i < 2; i++)
      for (std::size_t k = 0; k < 2; k++)
        for (std::size_t j = 0; j < 2; j++)
          checkmin(s[i][j], a_[i][k] + rhs[k][j]);
    return s;
  }
  ~Matrix() {}

 private:
  int a_[2][2];
};
class SegmentTree {
 public:
  SegmentTree() {}
  void Set(int n, int m, char *s1, char *s2) {
    n_ = n, m_ = m, s1_ = s1, s2_ = s2;
  }
  void Build(int l, int r, int x) {
    if (l == r) {
      for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
          t_[x].m_[i][j] = Get((s1_[l] == 'B') ^ i, (s2_[l] == 'B') ^ j);
      t_[x].s1 = s1_[l] == 'B', t_[x].s2 = s2_[l] == 'B';
      return;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
    Pushup(x);
  }
  void Modify1(int L, int R, int l, int r, int x) {
    if (L <= l && r <= R) return Tag1(l, r, x);
    Pushdown(l, r, x);
    int mid = (l + r) >> 1;
    if (L <= mid) Modify1(L, R, l, mid, x + x);
    if (R > mid) Modify1(L, R, mid + 1, r, x + x + 1);
    Pushup(x);
  }
  void Modify2(int L, int R, int l, int r, int x) {
    if (L <= l && r <= R) return Tag2(l, r, x);
    Pushdown(l, r, x);
    int mid = (l + r) >> 1;
    if (L <= mid) Modify2(L, R, l, mid, x + x);
    if (R > mid) Modify2(L, R, mid + 1, r, x + x + 1);
    Pushup(x);
  }
  Matrix sum() const { return t_[1].m_[0][0]; }
  int s1() const { return t_[1].s1; }
  int s2() const { return t_[1].s2; }
  ~SegmentTree() {}

 private:
  struct Node {
    Matrix m_[2][2];
    int s1, s2, tag1, tag2;
  } t_[400001];
  int n_, m_;
  char *s1_, *s2_;
  Matrix Get(int x, int y) {
    Matrix s;
    s[0][0] = x + y, s[0][1] = m_ + 2 - x - y;
    s[1][0] = m_ + x + y, s[1][1] = 2 - x - y;
    return s;
  }
  void Pushup(int x) {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        t_[x].m_[i][j] = t_[x + x].m_[i][j] * t_[x + x + 1].m_[i][j];
    t_[x].s1 = t_[x + x].s1 + t_[x + x + 1].s1;
    t_[x].s2 = t_[x + x].s2 + t_[x + x + 1].s2;
  }
  void Tag1(int l, int r, int x) {
    std::swap(t_[x].m_[0][0], t_[x].m_[1][0]);
    std::swap(t_[x].m_[0][1], t_[x].m_[1][1]);
    t_[x].s1 = r - l + 1 - t_[x].s1;
    t_[x].tag1 ^= 1;
  }
  void Tag2(int l, int r, int x) {
    std::swap(t_[x].m_[0][0], t_[x].m_[0][1]);
    std::swap(t_[x].m_[1][0], t_[x].m_[1][1]);
    t_[x].s2 = r - l + 1 - t_[x].s2;
    t_[x].tag2 ^= 1;
  }
  void Pushdown(int l, int r, int x) {
    int mid = (l + r) >> 1;
    if (t_[x].tag1) {
      Tag1(l, mid, x + x), Tag1(mid + 1, r, x + x + 1);
      t_[x].tag1 = 0;
    }
    if (t_[x].tag2) {
      Tag2(l, mid, x + x), Tag2(mid + 1, r, x + x + 1);
      t_[x].tag2 = 0;
    }
  }
} H, V;
int n, m, q;
char l[100005], r[100005], u[100005], d[100005];
void Solve() {
  auto m1 = H.sum(), m2 = V.sum();
  int ans = 0x3f3f3f3f;
  checkmin(ans, m1[0][0] + V.s1() + V.s2());
  checkmin(ans, m1[0][1] + V.s1() + m - V.s2());
  checkmin(ans, m1[1][0] + m - V.s1() + V.s2());
  checkmin(ans, m1[1][1] + m - V.s1() + m - V.s2());
  checkmin(ans, m2[0][0] + H.s1() + H.s2());
  checkmin(ans, m2[0][1] + H.s1() + n - H.s2());
  checkmin(ans, m2[1][0] + n - H.s1() + H.s2());
  checkmin(ans, m2[1][1] + n - H.s1() + n - H.s2());
  Write(ans, '\n');
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  Read(n, m, q), Read(l + 1), Read(r + 1), Read(u + 1), Read(d + 1);
  H.Set(n, m, l, r), V.Set(m, n, u, d);
  H.Build(1, n, 1), V.Build(1, m, 1);
  Solve();
  char op[10];
  while (q--) {
    int l, r;
    Read(op, l, r);
    if (op[0] == 'L') {
      H.Modify1(l, r, 1, n, 1);
    } else if (op[0] == 'R') {
      H.Modify2(l, r, 1, n, 1);
    } else if (op[0] == 'U') {
      V.Modify1(l, r, 1, m, 1);
    } else {
      V.Modify2(l, r, 1, m, 1);
    }
    Solve();
  }
  std::cout.write(wbuf, po - wbuf);
  return 0;
}