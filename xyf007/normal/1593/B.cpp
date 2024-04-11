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
int T;
std::string s;
void Solve() {
  std::cin >> s;
  std::reverse(s.begin(), s.end());
  std::vector<int> cnt(10), p[10];
  for (auto &&ch : s) cnt[ch - '0']++;
  for (std::size_t i = 0; i < s.size(); i++) p[s[i] - '0'].emplace_back(i);
  int ans = 0x3f3f3f3f;
  if (cnt[0] >= 2) checkmin(ans, p[0][1] - 1);
  if (cnt[0] && cnt[5]) {
    int p0 = p[0][0];
    auto it = std::lower_bound(p[5].begin(), p[5].end(), p0);
    if (it != p[5].end()) checkmin(ans, *it - 1);
  }
  if (cnt[2] && cnt[5]) {
    int p0 = p[5][0];
    auto it = std::lower_bound(p[2].begin(), p[2].end(), p0);
    if (it != p[2].end()) checkmin(ans, *it - 1);
  }
  if (cnt[7] && cnt[5]) {
    int p0 = p[5][0];
    auto it = std::lower_bound(p[7].begin(), p[7].end(), p0);
    if (it != p[7].end()) checkmin(ans, *it - 1);
  }
  std::cout << ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}