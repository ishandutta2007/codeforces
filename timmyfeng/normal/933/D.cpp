#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int M = 1e9 + 7;

int coefficient[4][4];

int add(int a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

int mod_pow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res;
}

int mod_inv(int a) {
  return mod_pow(a, M - 2);
}

const int F[4][8] = {
  {1, 1},
  {mod_inv(6), 1, 3, 2},
  {mod_inv(30), M - 1, 0, 10, 15, 6},
  {mod_inv(42), 1, 0, M - 7, 0, 21, 21, 6}
};

int choose(int n, int k) {
  int res = 1;
  for (int i = 0; i < k; ++i) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t m;
  cin >> m;

  coefficient[0][0] = mul(m % M, mul((m + 1) % M, (m + 2) % M));
  coefficient[0][1] = add(mul(3, m % M), 4);
  coefficient[0][2] = sub(0, add(mul(3, m % M), 6));
  coefficient[0][3] = 2;

  for (int i = 1; i < 4; ++i) {
    for (int j = 0; i + j < 4; ++j) {
      coefficient[i][j] = mul(choose(i + j, i), coefficient[0][i + j]);
    }
  }

  int ans = 0;
  int mx_y = N;

  for (int i = 0; 1LL * i * i <= m; ++i) {
    while (1LL * mx_y * mx_y + 1LL * i * i > m) {
      --mx_y;
    }

    for (int j = 0; j < 4; ++j) {
      int sum = 0;
      int power = 1;
      for (int k = 1; k <= j * 2 + 1; ++k) {
        power = mul(power, mx_y);
        sum = add(sum, mul(F[j][k], power));
      }
      sum = mul(sum, F[j][0]);
      sum = add(add(sum, sum), (j == 0));

      for (int k = 0; j + k < 4; ++k) {
        ans = add(ans, mul(sum, mul((i == 0) ? 1 : 2, mul(mod_pow(i, 2 * k), coefficient[j][k]))));
      }
    }
  }
  cout << mul(ans, mod_inv(6)) << "\n";
}