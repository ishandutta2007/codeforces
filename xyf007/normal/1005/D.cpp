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
int n, a[200001];
char s[200001];
bool f[3], g[3];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> (s + 1), n = std::strlen(s + 1);
  for (int i = 1; i <= n; i++) a[i] = (s[i] - '0') % 3;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (!a[i]) {
      ans++;
      std::memset(f, 0, sizeof(f));
    } else if (f[3 - a[i]]) {
      ans++;
      std::memset(f, 0, sizeof(f));
    } else {
      for (int j = 0; j < 3; j++) g[(j + a[i]) % 3] = f[j];
      for (int j = 0; j < 3; j++) f[j] = g[j];
      f[a[i]] = true;
    }
  std::cout << ans;
  return 0;
}