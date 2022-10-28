#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;

map<int, long long> read() {
  int x;
  cin >> x;
  map<int, long long> f;
  for (int i = 2; i * i <= x; ++i) {
    while (x % i == 0) {
      x /= i;
      ++f[i];
    }
  }
  if (x > 1) {
    ++f[x];
  }
  return f;
}

array<long long, 2> euclid(long long a, long long b) {
  if (b == 0) {
    return {(a > 0 ? 1 : -1), 0};
  }
  auto [x, y] = euclid(b, a % b);
  return {y, x - (a / b) * y};
}

long long floor_div(long long a, long long b) {
  return a / b - (a % b < 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<int, long long> a = read(), b = read();
  for (int i = 1; i < n; ++i) {
    map<int, long long> c = read(), d = read();

    set<int> primes;
    for (auto x : {&a, &b, &c, &d}) {
      for (auto [p, e] : *x) {
        primes.insert(p);
      }
    }

    long long ua = 0, ub = 0, uc = 0, x = -1, y = -1;
    for (auto p : primes) {
      long long va = b[p], vb = -d[p], vc = c[p] - a[p];
      long long det = ua * vb - ub * va;
      if (det == 0) {
        if (va == 0 && vb == 0) {
          if (vc != 0) {
            cout << -1 << "\n";
            exit(0);
          }
        } else if (ua * vc - uc * va == 0 && ub * vc - uc * vb == 0) {
          ua = va, ub = vb, uc = vc;
        } else {
          cout << -1 << "\n";
          exit(0);
        }
      } else {
        x = uc * vb - vc * ub;
        y = ua * vc - uc * va;
        if (x % det != 0 || y % det != 0 || x / det < 0 || y / det < 0) {
          cout << -1 << "\n";
          exit(0);
        }
        x /= det, y /= det;
        break;
      }
    }

    if (x != -1) {
      bool ok = true;
      for (auto p : primes) {
        long long va = b[p], vb = -d[p], vc = c[p] - a[p];
        ok &= (va * x + vb * y == vc);
        a[p] += b[p] * x;
      }
      b.clear();

      if (!ok) {
        cout << -1 << "\n";
        exit(0);
      }
    } else if (ua != 0 || ub != 0 || uc != 0) {
      long long g = abs(__gcd(ua, ub));
      if (uc % g != 0) {
        cout << -1 << "\n";
        exit(0);
      }

      if (ua == 0 || ub == 0) {
        if (uc / (ua + ub) < 0) {
          cout << -1 << "\n";
          exit(0);
        }
        if (ub == 0) {
          a = c, b = d;
        }
      } else {
        array<long long, 2> p = euclid(ua, ub);
        x = p[0] * uc / g, y = p[1] * uc / g;

        long long k = min(floor_div(x, -ub / g), floor_div(y, ua / g));
        x += k * ub / g, y -= k * ua / g;

        for (auto p : primes) {
          a[p] += b[p] * x;
          b[p] *= -ub / g;
        }
      }
    }
  }

  long long ans = 1;
  for (auto i : a) {
    long long p = i.first, e = i.second;
    while (e > 0) {
      if (e % 2 == 1) {
        ans = ans * p % M;
      }
      p = p * p % M;
      e /= 2;
    }
  }

  cout << ans << "\n";
}