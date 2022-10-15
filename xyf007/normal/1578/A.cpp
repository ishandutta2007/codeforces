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
int n, a[1000001], ans, min[2000001][2], sum[1000001];
void Solve(int bt) {
  std::memset(min, 0x3f, sizeof(min));
  int ff = 0;
  for (int i = 20; i > bt; i--) ff += 1 << i;
  for (int l = 1, r; l <= n; l++) {
    if (!((a[l] >> bt) & 1)) continue;
    r = l;
    while (r < n && ((a[r + 1] >> bt) & 1)) r++;
    for (int i = l; i <= r; i++) {
      checkmin(min[sum[i - 1] & ff][(i - 1) & 1], i - 1);
      checkmax(ans, i - min[sum[i] & ff][i & 1]);
    }
    for (int i = l; i <= r; i++) min[sum[i - 1] & ff][(i - 1) & 1] = 0x3f3f3f3f;
    l = r;
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] ^ a[i];
  for (int i = 20; i >= 0; i--) Solve(i);
  std::cout << ans;
  return 0;
}