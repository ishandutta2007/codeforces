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
char s[100001];
void Solve() {
  std::cin >> (s + 1), n = std::strlen(s + 1);
  int cnt = 0;
  for (int l = 1, r; l <= n; l = r + 1) {
    r = l;
    while (r < n && s[r + 1] == s[l]) r++;
    if (s[l] == '0') cnt++;
  }
  std::cout << std::min(cnt, 2) << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}