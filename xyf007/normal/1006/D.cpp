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
int n, cnt[26];
char a[100001], b[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> (a + 1) >> (b + 1);
  int l = 1, r = n, ans = 0;
  while (l <= r) {
    if (l == r) {
      ans += a[l] != b[l];
      break;
    }
    if (b[l] == b[r])
      ans += a[l] != a[r];
    else
      ans += std::min((a[l] != b[l]) + (a[r] != b[r]),
                      (a[l] != b[r]) + (a[r] != b[l]));
    l++, r--;
  }
  std::cout << ans;
  return 0;
}