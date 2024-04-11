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
int n, a[1000001], s[1000001], top, cnt[1000001], b[1000001], tot;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  int pos = std::max_element(a + 1, a + n + 1) - a;
  for (int i = pos + 1; i <= n; i++) b[++tot] = a[i];
  for (int i = 1; i < pos; i++) b[++tot] = a[i];
  long long ans = n - 1;
  for (int i = 1; i <= tot; i++) {
    while (top && s[top] < b[i]) ans += cnt[top--];
    if (s[top] != b[i]) s[++top] = b[i], cnt[top] = 0;
    ans += cnt[top]++;
  }
  while (top > 1) ans += cnt[top--];
  std::cout << ans;
  return 0;
}