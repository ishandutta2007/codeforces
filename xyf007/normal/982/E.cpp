#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
long long n, m, x, y, vx, vy;
void Exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  Exgcd(b, a % b, x, y);
  long long tmp = x;
  x = y;
  y = tmp - a / b * y;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m >> x >> y >> vx >> vy;
  if (!x && !y) {
    std::cout << "0 0";
    return 0;
  } else if (!x && y == m) {
    std::cout << "0 " << m;
    return 0;
  } else if (x == n && !y) {
    std::cout << n << " 0";
    return 0;
  } else if (x == n && y == m) {
    std::cout << n << ' ' << m;
    return 0;
  }
  if (!vx) {
    if (!vy) {
      std::cout << -1;
      return 0;
    } else {
      if (!x) {
        if (vy > 0) {
          std::cout << "0 " << m;
          return 0;
        } else {
          std::cout << "0 0";
          return 0;
        }
      } else if (x == n) {
        if (vy > 0) {
          std::cout << n << ' ' << m;
          return 0;
        } else {
          std::cout << n << " 0";
          return 0;
        }
      } else {
        std::cout << -1;
        return 0;
      }
    }
  }
  if (!vy) {
    if (!y) {
      if (vx > 0) {
        std::cout << n << " 0";
        return 0;
      } else {
        std::cout << "0 0";
        return 0;
      }
    } else if (y == m) {
      if (vx > 0) {
        std::cout << n << ' ' << m;
        return 0;
      } else {
        std::cout << "0 " << m;
        return 0;
      }
    } else {
      std::cout << -1;
      return 0;
    }
  }
  long long a = 0, b = 0, gcd = std::__gcd(n, m), s = vx * x - vy * y;
  if (s % gcd) {
    std::cout << -1;
    return 0;
  }
  n /= gcd;
  m /= gcd;
  s /= gcd;
  Exgcd(n, m, a, b);
  a *= s;
  b *= s;
  if (a < 0 || (vx > 0 && !a)) {
    long long t = (-a) / m + 1;
    a = a % m + m;
    b -= t * n;
  } else if (b > 0) {
    long long t = b / n + 1;
    b = b % n - n;
    a += t * m;
  }
  long long t1 = a / m;
  if (vx > 0 && !(a % m)) {
    t1--;
  }
  a -= t1 * m;
  b += t1 * n;
  b = -b;
  n *= gcd;
  m *= gcd;
  if (a & 1) {
    std::cout << n << ' ';
  } else {
    std::cout << "0 ";
  }
  if (b & 1) {
    std::cout << m;
  } else {
    std::cout << 0;
  }
  return 0;
}