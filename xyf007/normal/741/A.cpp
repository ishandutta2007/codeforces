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
int n, p[101], ind[101];
bool vis[101];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> p[i], ind[p[i]]++;
  for (int i = 1; i <= n; i++)
    if (!ind[i]) {
      std::cout << -1;
      return 0;
    }
  int ans = 1;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      int c = 1;
      vis[i] = true;
      for (int j = p[i]; j != i; j = p[j]) {
        vis[j] = true;
        c++;
      }
      if (!(c & 1)) c >>= 1;
      int gcd = std::__gcd(ans, c);
      ans = ans / gcd * c;
    }
  std::cout << ans;
  return 0;
}