#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, a, b;
  cin >> n >> k >> a >> b;
  int64_t x = 1e18, y = -1e18;
  for (int64_t s : {a, k - a}) {
    for (int i = 0; i < n; ++i) {
      for (int64_t t : {1LL * i * k + b, 1LL * (i + 1) * k - b}) {
        {
          int64_t l = ((t - s) % (1LL * n * k) + (1LL * n * k)) % (1LL * n * k);
          if (l == 0) l = 1LL * n * k;
          int64_t g = __gcd(l, 1LL * n * k);
          int64_t v = 1LL * n * k / g;
          x = min(x, v);
          y = max(y, v);
        }
        {
          int64_t l = ((s - t) % (1LL * n * k) + (1LL * n * k)) % (1LL * n * k);
          if (l == 0) l = 1LL * n * k;
          int64_t g = __gcd(l, 1LL * n * k);
          int64_t v = 1LL * n * k / g;
          x = min(x, v);
          y = max(y, v);
        }
      }
    }
  }
  cout << x << " " << y << "\n";
}