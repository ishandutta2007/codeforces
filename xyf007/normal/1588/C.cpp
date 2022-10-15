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
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
int T, n, cnt, lg[300001];
long long a[300001], s[300001], min[2][20][300001];
std::map<long long, int> id;
std::vector<int> pos[2][300005];
inline long long Query(int _, int l, int r) {
  int len = lg[r - l + 1];
  return std::min(min[_][len][l], min[_][len][r - (1 << len) + 1]);
}
inline int Query(const std::vector<int> &v, int l, int r) {
  return std::upper_bound(v.begin(), v.end(), r) -
         std::lower_bound(v.begin(), v.end(), l);
}
void Clear() {
  for (int _ = 0; _ <= 1; _++)
    for (int i = 1; i <= cnt; i++) std::vector<int>().swap(pos[_][i]);
  std::map<long long, int>().swap(id), cnt = 0;
}
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) s[i] = a[i] - s[i - 1];
  for (int i = 0; i <= n; i++) {
    if (!id.count(s[i])) id[s[i]] = ++cnt;
    pos[i & 1][id[s[i]]].push_back(i);
  }
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  std::memset(min[0][0] + 1, 0x3f, 8 * n);
  std::memset(min[1][0] + 1, 0x3f, 8 * n);
  for (int i = 1; i <= n; i += 2) min[1][0][i] = s[i];
  for (int i = 2; i <= n; i += 2) min[0][0][i] = s[i];
  for (int _ = 0; _ <= 1; _++)
    for (int j = 1; j <= lg[n]; j++)
      for (int i = 1; i <= n - (1 << j) + 1; i++)
        min[_][j][i] =
            std::min(min[_][j - 1][i], min[_][j - 1][i + (1 << (j - 1))]);
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) {
    int l = i, r = n, best = i;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (Query(i & 1, i, mid) >= -s[i - 1] &&
          Query(~i & 1, i, mid) >= s[i - 1])
        best = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    ans += Query(pos[i & 1][id[-s[i - 1]]], i, best) +
           Query(pos[~i & 1][id[s[i - 1]]], i, best);
  }
  std::cout << ans << '\n';
  Clear();
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}