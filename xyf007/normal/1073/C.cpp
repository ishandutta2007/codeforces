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
int n, x, y;
char s[200001];
std::pair<int, int> pre[200001], suf[200002];
std::pair<int, int> operator+(const std::pair<int, int> &lhs,
                              const std::pair<int, int> &rhs) {
  return {lhs.first + rhs.first, lhs.second + rhs.second};
}
bool Check(int mid) {
  for (int i = 1; i <= n - mid + 1; i++) {
    std::pair<int, int> now = pre[i - 1] + suf[i + mid];
    int dx = std::abs(x - now.first), dy = std::abs(y - now.second);
    if (dx + dy <= mid && !((mid - dx - dy) & 1)) return true;
  }
  return false;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> (s + 1) >> x >> y;
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1];
    if (s[i] == 'L') pre[i].first--;
    if (s[i] == 'R') pre[i].first++;
    if (s[i] == 'U') pre[i].second++;
    if (s[i] == 'D') pre[i].second--;
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1];
    if (s[i] == 'L') suf[i].first--;
    if (s[i] == 'R') suf[i].first++;
    if (s[i] == 'U') suf[i].second++;
    if (s[i] == 'D') suf[i].second--;
  }
  int l = 0, r = n, best = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (Check(mid)) {
      best = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  std::cout << best;
  return 0;
}