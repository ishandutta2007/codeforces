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
int n, m, a[50001], b[50001], p[50001], r[50001];
std::string s;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> s;
  n = s.size(), m = std::count(s.begin(), s.end(), '?');
  for (int i = 1; i <= m; i++) std::cin >> a[i] >> b[i];
  int c = 0, cnt = 0;
  long long ans = 0LL;
  for (int i = 0; i < n; i++)
    if (s[i] == '?') r[p[i] = ++c] = i;
  std::priority_queue<std::pair<int, int>> q;
  for (int i = 0; i < n; i++)
    if (s[i] == '(') {
      cnt++;
    } else {
      cnt--;
      if (s[i] == '?')
        ans += b[p[i]], q.emplace(b[p[i]] - a[p[i]], i), s[i] = ')';
      if (cnt < 0) {
        if (q.empty()) {
          std::cout << -1;
          return 0;
        }
        auto [w, pos] = q.top();
        q.pop();
        ans -= w, s[pos] = '(';
        cnt = 1;
      }
    }
  if (cnt) {
    std::cout << -1;
    return 0;
  }
  std::cout << ans << '\n' << s;
  return 0;
}