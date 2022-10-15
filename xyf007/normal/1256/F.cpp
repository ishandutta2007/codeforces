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
int T, n, cnt[26];
char s[200001], t[200001];
void Solve() {
  std::cin >> n >> (s + 1) >> (t + 1);
  std::memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) cnt[s[i] - 'a']++;
  for (int i = 1; i <= n; i++) cnt[t[i] - 'a']--;
  for (int i = 0; i < 26; i++)
    if (cnt[i]) {
      std::cout << "NO\n";
      return;
    }
  for (int i = 1; i <= n; i++) cnt[s[i] - 'a']++;
  for (int i = 0; i < 26; i++)
    if (cnt[i] > 1) {
      std::cout << "YES\n";
      return;
    }
  int r1 = 0, r2 = 0;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) r1 += s[i] > s[j];
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) r2 += t[i] > t[j];
  std::cout << ((r1 + r2) & 1 ? "NO\n" : "YES\n");
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}