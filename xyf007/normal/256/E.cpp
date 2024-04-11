#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
constexpr int kMod = 777777777;
int add(int a, int b) { return (a + b) % kMod; }
template <typename... Args>
int add(int a, int b, Args... args) {
  return add(add(a, b), args...);
}
int sub(int a, int b) { return (a + kMod - b) % kMod; }
int mul(int a, int b) { return a * static_cast<long long>(b) % kMod; }
template <typename... Args>
int mul(int a, int b, Args... args) {
  return mul(mul(a, b), args...);
}
void Add(int &a, int b) { a = add(a, b); }
template <typename... Args>
void Add(int &a, int b, Args... args) {
  Add(a, add(b, args...));
}
void Sub(int &a, int b) { a = sub(a, b); }
void Mul(int &a, int b) { a = mul(a, b); }
template <typename... Args>
void Mul(int &a, int b, Args... args) {
  Mul(a, mul(b, args...));
}
int n, m;
class Matrix {
 public:
  int a_[3][3];
  Matrix() { std::memset(a_, 0, sizeof(a_)); }
  Matrix operator*(const Matrix &) const;
  Matrix &operator*=(const Matrix &rhs) { return *this = *this * rhs; }
  ~Matrix() {}
} w[4], t[311111];

Matrix Matrix::operator*(const Matrix &rhs) const {
  Matrix s;
  for (int i = 0; i < 3; i++) {
    for (int k = 0; k < 3; k++) {
      for (int j = 0; j < 3; j++) {
        Add(s.a_[i][j], mul(a_[i][k], rhs.a_[k][j]));
      }
    }
  }
  return s;
}
void Pushup(int x) { t[x] = t[x + x] * t[x + x + 1]; }
void Build(int l, int r, int x) {
  if (l > r) {
    return;
  }
  if (l == r) {
    t[x] = w[0];
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x);
  Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify(int l, int r, int p, const Matrix &v, int x) {
  if (l > r) {
    return;
  }
  if (l == r) {
    t[x] = v;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) {
    Modify(l, mid, p, v, x + x);
  } else {
    Modify(mid + 1, r, p, v, x + x + 1);
  }
  Pushup(x);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cin >> w[0].a_[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    w[1].a_[i][0] = w[0].a_[i][0];
    w[2].a_[i][1] = w[0].a_[i][1];
    w[3].a_[i][2] = w[0].a_[i][2];
  }
  t[1].a_[0][0] = t[1].a_[1][1] = t[1].a_[2][2] = 1;
  Build(1, n - 1, 1);
  Matrix m1, ans;
  m1.a_[0][0] = m1.a_[0][1] = m1.a_[0][2] = 1;
  for (int i = 1; i <= m; i++) {
    int p, v;
    std::cin >> p >> v;
    if (p == 1) {
      if (!v) {
        m1.a_[0][0] = m1.a_[0][1] = m1.a_[0][2] = 1;
      } else {
        m1.a_[0][0] = m1.a_[0][1] = m1.a_[0][2] = 0;
        m1.a_[0][v - 1] = 1;
      }
    } else {
      Modify(1, n - 1, p - 1, w[v], 1);
    }
    ans = m1 * t[1];
    std::cout << add(ans.a_[0][0], ans.a_[0][1], ans.a_[0][2]) << '\n';
  }
  return 0;
}