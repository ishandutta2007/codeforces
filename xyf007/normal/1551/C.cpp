#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Node {
  int cnt[5], len;
} a[200001];
int t, n, p;
std::string s[200001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> s[i];
      a[i].len = s[i].size();
      std::memset(a[i].cnt, 0, sizeof(a[i].cnt));
      for (auto &&c : s[i]) a[i].cnt[c - 'a']++;
    }
    int ans = 0;
    for (p = 0; p < 5; p++) {
      std::sort(a + 1, a + n + 1, [](const Node &lhs, const Node &rhs) {
        return lhs.cnt[p] * 2 - lhs.len > rhs.cnt[p] * 2 - rhs.len;
      });
      int sum = 0;
      for (int i = 1; i <= n; i++) {
        sum += 2 * a[i].cnt[p] - a[i].len;
        if (sum <= 0) break;
        checkmax(ans, i);
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}