#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n, a[100001], ans[100001];
bool f[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  long long v = a[n];
  std::fill(ans + 1, ans + n, -1);
  ans[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    if (v >= a[i]) {
      v -= a[i];
    } else {
      v = a[i] - v;
      f[i] = true;
    }
  }
  int op = -1;
  for (int i = 1; i < n; i++) {
    if (f[i]) {
      op *= -1;
    }
    std::cout << (op < 0 ? '-' : '+');
  }
  std::cout << (op < 0 ? '+' : '-');
  return 0;
}