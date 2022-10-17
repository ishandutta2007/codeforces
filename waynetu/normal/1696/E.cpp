#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<int> a(N + 1);
  for (int i = 0; i <= N; ++i) {
    cin >> a[i];
  }
  constexpr int kP = 1'000'000'000 + 7;
  constexpr int kC = 1'000'000;

  auto fpow = [&](int a, int n) {
    int res = 1;
    while (n > 0) {
      if (n & 1) {
        res = 1LL * res * a % kP;
      }
      a = 1LL * a * a % kP;
      n >>= 1;
    }
    return res;
  };

  vector<int> fc(kC, 1), iv(kC, 1);
  for (int i = 1; i < kC; ++i) {
    fc[i] = 1LL * fc[i - 1] * i % kP;
    iv[i] = fpow(fc[i], kP - 2);
  }

  auto Bin = [&](int n, int k) {
    return 1LL * fc[n] * iv[k] % kP * iv[n - k] % kP;
  };

  int ans = 0;
  for (int i = 0; i <= N; ++i) {
    if (a[i] > 0) {
      ans += Bin(i + a[i], a[i] - 1);
      ans %= kP;
    }
    // for (int j = 0; j < a[i]; ++j) {
    //   ans += Bin(i + j, j);
    //   ans %= kP;
    // }
  }
  cout << ans << "\n";
  return 0;
}