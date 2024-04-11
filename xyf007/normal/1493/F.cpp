#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
struct Rectangle {
  int x1, y1, x2, y2;
  Rectangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0)
      : x1(x1), y1(y1), x2(x2), y2(y2) {}
  Rectangle(const Rectangle &l, const Rectangle &r) {
    x1 = l.x1;
    y1 = l.y1;
    x2 = r.x2;
    y2 = r.y2;
  }
};
int n, m, dp[1001];
std::vector<Rectangle> v;
bool Ask(const Rectangle &a, const Rectangle &b) {
  int h = a.x2 - a.x1 + 1, w = a.y2 - a.y1 + 1;
  std::cout << "? " << h << ' ' << w << ' ' << a.x1 << ' ' << a.y1 << ' '
            << b.x1 << ' ' << b.y1 << std::endl;
  bool ans;
  std::cin >> ans;
  return ans;
}
bool Check(size_t l, size_t r) {
  if (l == r) {
    return true;
  }
  size_t len = (r - l + 1) >> 1;
  if (Ask(Rectangle(v.at(l), v.at(l + len - 1)),
          Rectangle(v.at(l + len), v.at(l + 2 * len - 1)))) {
    return Check(l + len, r);
  }
  return false;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m;
  std::memset(dp, -1, sizeof(dp));
  int cnt0 = 0, cnt1 = 0;
  for (int i = n; i >= 1; i--) {
    if (n % i || dp[i] != -1) {
      continue;
    }
    for (int j = i + i; j <= n; j += i) {
      if (!(n % j)) {
        std::vector<Rectangle>().swap(v);
        for (int k = 1; k <= j / i; k++) {
          v.emplace_back((k - 1) * i + 1, 1, k * i, m);
        }
        dp[i] = Check(0, v.size() - 1);
        break;
      }
    }
    if (!dp[i]) {
      for (int j = 1; j <= i; j++) {
        if (!(i % j)) {
          dp[j] = 0;
        }
      }
    } else {
      dp[i] = 1;
      for (int j = i; j <= n; j++) {
        if (dp[j] == 1) {
          int gcd = std::__gcd(i, j);
          for (int k = gcd; k <= n; k += gcd) {
            dp[k] = 1;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!(n % i)) {
      cnt0 += dp[i] == 1;
    }
  }
  std::memset(dp, -1, sizeof(dp));
  for (int i = m; i >= 1; i--) {
    if (m % i || dp[i] != -1) {
      continue;
    }
    for (int j = i + i; j <= m; j += i) {
      if (!(m % j)) {
        std::vector<Rectangle>().swap(v);
        for (int k = 1; k <= j / i; k++) {
          v.emplace_back(1, (k - 1) * i + 1, n, k * i);
        }
        dp[i] = Check(0, v.size() - 1);
        break;
      }
    }
    if (!dp[i]) {
      for (int j = 1; j <= i; j++) {
        if (!(i % j)) {
          dp[j] = 0;
        }
      }
    } else {
      dp[i] = 1;
      for (int j = i; j <= m; j++) {
        if (dp[j] == 1) {
          int gcd = std::__gcd(i, j);
          for (int k = gcd; k <= m; k += gcd) {
            dp[k] = 1;
          }
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (!(m % i)) {
      cnt1 += dp[i] == 1;
    }
  }
  std::cout << "! " << cnt0 * cnt1 << std::endl;
  return 0;
}