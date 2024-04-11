#include <functional>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <class T, typename = decltype(std::declval<T>().begin()),
          typename = decltype(std::declval<T>().end()),
          typename = typename std::enable_if<!std::is_base_of<
              std::string, typename std::decay<T>::type>::value>::type,
          typename value_type = typename T::value_type>
std::ostream &operator<<(std::ostream &out, const T &container) {
  for (auto it = container.begin(); it != container.end(); ++it)
    out << *it << ' ';
  return out;
}
std::ostream &operator<<(std::ostream &out, __int128_t x) {
  if (!x) return out << 0;
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
int T, n, k, a[100001], c[100001];
void Solve() {
  std::cin >> n >> k;
  std::map<int, int> mp;
  for (int i = 1; i <= n; i++) std::cin >> a[i], mp[a[i]]++;
  if (k == 0) {
    int mex = 0;
    while (mp.count(mex)) mex++;
    std::cout << (int)mp.size() - mex << '\n';
    return;
  }
  c[0] = !mp.count(0);
  for (int i = 1; i <= n; i++) c[i] = c[i - 1] + !mp.count(i);
  std::priority_queue<int> q1;
  std::priority_queue<int, std::vector<int>, std::greater<int>> q2;
  for (const auto &[x, c] : mp)
    if (x >= n) q2.emplace(c);
  int sz = 0;
  while (!q2.empty()) {
    auto x = q2.top();
    if (sz + x <= k) {
      sz += x, q1.emplace(x), q2.pop();
    } else {
      break;
    }
  }
  int ans = 0x3f3f3f3f;
  for (int i = n - 1; i >= 0; i--) {
    if (c[i] <= k) checkmin(ans, (int)q2.size());
    if (mp.count(i)) {
      if (!q1.empty() && mp[i] < q1.top()) {
        sz -= q1.top(), q2.emplace(q1.top()), q1.pop();
        sz += mp[i], q1.emplace(mp[i]);
      } else {
        q2.emplace(mp[i]);
      }
      while (!q2.empty()) {
        int x = q2.top();
        if (sz + x <= k) {
          sz += x, q1.emplace(x), q2.pop();
        } else {
          break;
        }
      }
    }
  }
  std::cout << ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}