#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int k, n;
long long a[200001], pre[200001], suf[200002];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
  for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];
  long long ans = std::numeric_limits<long long>().max();
  for (int l = 1, r; l <= n; l = r + 1) {
    r = l;
    while (r < n && a[r + 1] == a[l]) r++;
    if (r - l + 1 >= k) {
      std::cout << 0;
      return 0;
    }
    int rem = k - (r - l + 1);
    long long fl = (a[l] - 1) * (l - 1) - pre[l - 1],
              fr = suf[r + 1] - (a[l] + 1) * (n - r);
    if (l - 1 >= rem)
      checkmin(ans, fl + rem);
    else
      checkmin(ans, fl + l - 1 + fr + rem - (l - 1));
    if (n - r >= rem)
      checkmin(ans, fr + rem);
    else
      checkmin(ans, fr + n - r + fl + rem - (n - r));
  }
  std::cout << ans;
  return 0;
}