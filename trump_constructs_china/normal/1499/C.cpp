#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int t, n;
long long a[100001];
void checkmin(long long &x, long long y) {
  if (x > y) {
    x = y;
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    long long ans = (a[1] + a[2]) * n, ans1 = a[1] * n, ans2 = a[2] * n,
              min1 = a[1], min2 = a[2], len1 = n, len2 = n;
    for (int i = 3; i <= n; i++) {
      if (i & 1) {
        if (a[i] < min1) {
          ans1 -= (min1 - a[i]) * --len1;
          min1 = a[i];
        } else {
          ans1 += a[i] - min1;
          len1--;
        }
      } else {
        if (a[i] < min2) {
          ans2 -= (min2 - a[i]) * --len2;
          min2 = a[i];
        } else {
          ans2 += a[i] - min2;
          len2--;
        }
      }
      checkmin(ans, ans1 + ans2);
    }
    std::cout << ans << '\n';
  }
  return 0;
}