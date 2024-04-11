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
int k, n, q, cnt[1000001];
char s[300001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> k >> (s + 1);
  n = (1 << k) - 1;
  std::reverse(s + 1, s + n + 1);
  std::fill(cnt + (1 << k), cnt + (1 << (k + 1)), 1);
  for (int i = n; i >= 1; i--) {
    if (s[i] != '1') cnt[i] += cnt[2 * i + 1];
    if (s[i] != '0') cnt[i] += cnt[2 * i];
  }
  std::cin >> q;
  while (q--) {
    int p;
    char op[10];
    std::cin >> p >> op;
    s[p = n - p + 1] = op[0];
    while (p) {
      cnt[p] = 0;
      if (s[p] != '1') cnt[p] += cnt[2 * p + 1];
      if (s[p] != '0') cnt[p] += cnt[2 * p];
      p >>= 1;
    }
    std::cout << cnt[1] << '\n';
  }
  return 0;
}