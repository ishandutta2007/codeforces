#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  constexpr int kP = 1'000'000'000 + 7;

  auto fpow = [&](int a, int n) {
    int res = 1;
    while (n > 0) {
      if (n & 1) res = 1LL * res * a % kP;
      a = 1LL * a * a % kP;
      n >>= 1;
    }
    return res;
  };

  vector<vector<int>> p(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == j) continue;
      p[i][j] = 1LL * A[i] * fpow(A[i] + A[j], kP - 2) % kP;
    }
  }

  vector<int> dp(1 << N);
  for (int s = 1; s < (1 << N); ++s) {
    int sum = 0;
    for (int sub = (s - 1) & s; sub > 0; sub = (sub - 1) & s) {
      int t = 1;
      for (int i = 0; i < N; ++i) {
        if (sub >> i & 1) {
          for (int j = 0; j < N; ++j) {
            if ((s ^ sub) >> j & 1) {
              t = 1LL * t * p[i][j] % kP;
            }
          }
        }
      }
      sum += 1LL * t * dp[sub] % kP;
      sum %= kP;
    }
    dp[s] = kP + 1 - sum;
  }
  int ans = 0;
  for (int s = 1; s < (1 << N); ++s) {
    int t = 1;
    for (int i = 0; i < N; ++i) {
      if (s >> i & 1) {
        for (int j = 0; j < N; ++j) {
          if (!(s >> j & 1)) {
            t = 1LL * t * p[i][j] % kP;
          }
        }
      }
    }
    ans += 1LL * t * __builtin_popcount(s) % kP * dp[s] % kP;
    ans %= kP;
  }
  cout << ans << "\n";
  return 0;
}