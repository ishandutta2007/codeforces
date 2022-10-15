#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int m;
long long L, R, k;
class Matrix {
 public:
  int a_[2][2];
  Matrix() { std::memset(a_, 0, sizeof(a_)); }
  Matrix operator*(const Matrix &) const;
  Matrix &operator*=(const Matrix &b) { return *this = *this * b; }
  ~Matrix() {}
} A, tran;

Matrix Matrix::operator*(const Matrix &b) const {
  Matrix s;
  for (int i = 0; i < 2; i++) {
    for (int k = 0; k < 2; k++) {
      for (int j = 0; j < 2; j++) {
        s.a_[i][j] =
            (s.a_[i][j] + static_cast<long long>(a_[i][k]) * b.a_[k][j]) % m;
      }
    }
  }
  return s;
}
Matrix Ksm(Matrix a, long long b) {
  Matrix s;
  for (int i = 0; i < 2; i++) {
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
  std::cin >> m >> L >> R >> k;
  L--;
  long long ans = 0LL;
  for (long long l = 1, r; l <= R; l = r + 1) {
    r = L / l ? std::min(L / (L / l), R / (R / l)) : R / (R / l);
    if (R / l - L / l >= k) {
      ans = r;
    }
  }
  A.a_[0][0] = tran.a_[0][0] = tran.a_[0][1] = tran.a_[1][0] = 1;
  std::cout << (Ksm(tran, ans - 1) * A).a_[0][0] % m;
  return 0;
}