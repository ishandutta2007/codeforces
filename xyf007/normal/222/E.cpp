#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
constexpr int kMod = 1e9 + 7;
long long n;
int m, k;
char s[10];
class Matrix {
 public:
  int a_[52][52];
  Matrix() { std::memset(a_, 0, sizeof(a_)); }
  Matrix operator*(const Matrix &) const;
  Matrix &operator*=(const Matrix &b) { return *this = *this * b; };
  ~Matrix() {}
} A, tran;

Matrix Matrix::operator*(const Matrix &b) const {
  Matrix s;
  for (int i = 0; i < m; i++) {
    for (int k = 0; k < m; k++) {
      for (int j = 0; j < m; j++) {
        s.a_[i][j] =
            (s.a_[i][j] + static_cast<long long>(a_[i][k]) * b.a_[k][j]) % kMod;
      }
    }
  }
  return s;
}
Matrix Ksm(Matrix a, long long b) {
  Matrix s;
  for (int i = 0; i < m; i++) {
    s.a_[i][i] = 1;
  }
  while (b) {
    if (b & 1) {
      s *= a;
    }
    a *= a;
    b >>= 1;
  }
  return s;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m >> k;
  auto decode = [](const char &x) -> int {
    return x <= 'Z' ? x - 'A' + 26 : x - 'a';
  };
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      tran.a_[i][j] = 1;
    }
    A.a_[i][0] = 1;
  }
  for (int i = 1; i <= k; i++) {
    std::cin >> s;
    int x = decode(s[0]), y = decode(s[1]);
    tran.a_[y][x] = 0;
  }
  A = Ksm(tran, n - 1) * A;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    ans = (ans + A.a_[i][0]) % kMod;
  }
  std::cout << ans;
  return 0;
}