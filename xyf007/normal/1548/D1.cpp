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
constexpr int kPat[16][3] = {{0, 0, 0}, {0, 0, 1}, {0, 0, 2}, {0, 0, 3},
                             {0, 1, 1}, {0, 2, 2}, {0, 3, 3}, {1, 1, 1},
                             {1, 1, 2}, {1, 1, 3}, {1, 2, 2}, {1, 3, 3},
                             {2, 2, 2}, {2, 2, 3}, {2, 3, 3}, {3, 3, 3}};
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n;
std::pair<int, int> b[6001];
long long cnt[11];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i].first >> b[i].second;
    b[i].first >>= 1, b[i].second >>= 1;
    cnt[((b[i].first & 1) << 1) + (b[i].second & 1)]++;
  }
  long long ans = 0LL;
  for (int i = 0; i < 16; i++) {
    int x = kPat[i][0], y = kPat[i][1], z = kPat[i][2];
    if (x == y && y == z)
      ans += cnt[x] * (cnt[x] - 1) * (cnt[x] - 2) / 6;
    else if (x == y)
      ans += cnt[x] * (cnt[x] - 1) / 2 * cnt[z];
    else if (y == z)
      ans += cnt[x] * cnt[y] * (cnt[y] - 1) / 2;
  }
  std::cout << ans;
  return 0;
}