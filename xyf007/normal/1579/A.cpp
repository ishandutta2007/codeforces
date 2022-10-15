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
int T, n, cnt[101];
char s[1001];
void Solve() {
  std::memset(cnt, 0, sizeof(cnt));
  std::cin >> (s + 1), n = std::strlen(s + 1);
  for (int i = 1; i <= n; i++) cnt[s[i] - 'A']++;
  if (cnt[1] == cnt[0] + cnt[2])
    std::cout << "YES\n";
  else
    std::cout << "NO\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}