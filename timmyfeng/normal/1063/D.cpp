#include <bits/stdc++.h>
using namespace std;

const int O = 2e4;

long long floor_div(long long a, long long b) {
  return a / b - ((a ^ b) < 0 && a % b != 0);
}

tuple<long long, long long, long long> gcd(long long a, long long b) {
  if (b == 0)
    return {a, 1, 0};
  auto [g, x, y] = gcd(b, a % b);
  return {g, y, x - y * (a / b)};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, l, r, k;
  cin >> n >> l >> r >> k;

  l = r - l + 1;
  if (l <= 0) {
    l += n;
  }
  r = n - l;

  long long ans = -1;
  if (n <= O) {
    for (long long i = 0; i <= l; ++i) {
      for (long long j = 0; j <= r; ++j) {
        long long res = (k - l - i) % (i + j + n);
        if (res > 0) {
          res -= i + j + n;
        }
        if (res == 0 || (i > 0 && res == -1)) {
          ans = max(ans, i + j);
        }
      }
    }
  } else {
    for (long long i = 0; i * n <= k; ++i) {
      auto [g, x, y] = gcd(i + 1, i);
      long long c = k - n * i - l;

      for (int phase = 0; phase < 2; ++phase, ++c) {
        if (c < 0)
          continue;

        long long xx = x * c;
        long long yy = y * c;

        if (i == 0) {
          if (xx >= phase && xx <= l) {
            ans = max(ans, xx + r);
          }
        } else {
          long long max_k = min(floor_div(xx - phase, i), floor_div(r - yy, i + 1));
          if (xx - max_k * i <= l && yy + max_k * (i + 1) >= 0) {
            ans = max(ans, xx + yy + max_k);
          }
        }
      }
    }
  }

  cout << ans << "\n";
}