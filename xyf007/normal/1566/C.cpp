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
int T, n;
char s[3][100005];
void Solve() {
  std::cin >> n >> (s[0] + 1) >> (s[1] + 1);
  int ans = 0, l0 = 0;
  for (int l = 1, r; l <= n; l = r + 1) {
    r = l;
    if (s[0][l] != s[1][l]) {
      ans += 2;
      continue;
    }
    while (r < n && s[0][r + 1] == s[0][l] && s[1][r + 1] == s[1][r]) r++;
    if (s[0][l] == '0') {
      ans += r - l + 1;
    } else {
      int f = 0;
      if (l && l - 1 != l0 && s[0][l - 1] == '0' && s[1][l - 1] == '0')
        ans++, f = 1;
      if ((!f || r > l) && r < n && s[0][r + 1] == '0' && s[1][r + 1] == '0')
        ans++, l0 = r + 1;
    }
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