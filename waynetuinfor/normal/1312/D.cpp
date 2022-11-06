#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  constexpr int kMod = 998244353;

  auto fpow = [&](int a, int n) {
    int res = 1;
    while (n > 0) {
      if (n & 1) res = 1LL * res * a % kMod;
      a = 1LL * a * a % kMod;
      n >>= 1;
    }
    return res;
  };

  vector<int> fc(m + 1, 1), iv(m + 1, 1);
  for (int i = 1; i <= m; ++i) fc[i] = 1LL * fc[i - 1] * i % kMod;
  iv[m] = fpow(fc[m], kMod - 2);
  for (int i = m - 1; i > 0; --i) iv[i] = 1LL * iv[i + 1] * (i + 1) % kMod;

  auto Choose = [&](int n, int k) {
    if (n < k || k < 0) return 0LL;
    return 1LL * fc[n] * iv[k] % kMod * iv[n - k] % kMod;
  };

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    int res = Choose(m, n - 1);
    res = 1LL * res * Choose(n - 2, i) % kMod * i % kMod;
    (ans += res) %= kMod;
  }
  cout << ans << "\n";
  return 0;
}