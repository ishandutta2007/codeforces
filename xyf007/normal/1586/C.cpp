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
int n, m, q;
std::string s[1000001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> s[i];
  for (int i = 1; i <= n; i++) s[i] = ' ' + s[i];
  std::vector<int> a;
  for (int i = 2; i <= m; i++) {
    bool f = false;
    for (int j = 2; j <= n; j++)
      if (s[j - 1][i] == 'X' && s[j][i - 1] == 'X') f = true;
    if (f) a.emplace_back(i);
  }
  a.emplace_back(m + 1);
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    int fir = *std::upper_bound(a.begin(), a.end(), l);
    if (fir <= r)
      std::cout << "NO\n";
    else
      std::cout << "YES\n";
  }
  return 0;
}