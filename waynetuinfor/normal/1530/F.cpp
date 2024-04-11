#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

constexpr int kN = 21;
int p[kN][kN][2];
uint16_t dp[1 << (kN + 2)];
uint16_t row[1 << (kN + 2)];

int main() {
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N));
  constexpr int kP = 31607;

  auto fpow = [&](int a, int n) {
    int res = 1;
    while (n > 0) {
      if (n & 1) res = res * a % kP;
      a = a * a % kP;
      n >>= 1;
    }
    return res;
  };

  const int kI = fpow(10000, kP - 2);
  dp[0] = 1;
  for (int i = 0; i < N; ++i) {
    memcpy(row, dp, (1 << (N + 3)));
    int all = 1;
    for (int j = 0; j < N; ++j) {
      int A;
      cin >> A;
      int p1 = A * kI % kP;
      int p0 = (kP + 1 - p1) % kP;
      all = all * p1 % kP;
      if (i == j || i + j == N - 1) {
        int add = 0;
        if (i == j) add |= (1 << N);
        if (i + j == N - 1) add |= (1 << (N + 1));
        for (int s = (1 << (N + 2)) - 1; s >= 0; --s) {
          int ns = s | (1 << j) | add;
          if (ns > s) {
            row[ns] = (row[ns] + p0 * row[s]) % kP;
            row[s] = row[s] * p1 % kP;
          }
        }
      } else {
        for (int s = (1 << (N + 2)) - 1; s >= 0; --s) {
          if (s >> j & 1) continue;
          int ns = s ^ (1 << j);
          row[ns] = (row[ns] + p0 * row[s]) % kP;
          row[s] = row[s] * p1 % kP;
        }
      }
    }
    for (int s = 0; s < (1 << (N + 2)); ++s) {
      dp[s] = (row[s] + kP - all * dp[s] % kP) % kP;
    }
  }
  cout << (kP + 1 - dp[(1 << (N + 2)) - 1]) % kP << "\n";
  return 0;
}