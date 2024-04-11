#include <cstring>
#include <iostream>
#include <vector>
constexpr __int128_t operator""_LLL(unsigned long long x) {
  return static_cast<__int128_t>(x);
}
constexpr __int128_t kLim = 2000000000000000000_LLL;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int T, n;
long long k;
__int128_t f[101], g[101];
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
void Init() {
  g[1] = g[2] = 1_LLL;
  for (int i = 3; i <= 60; i++) {
    g[i] = g[i - 1] * (i - 2);
    checkmin(g[i], kLim);
  }
  f[0] = 1_LLL;
  for (int i = 1; i <= 60; i++)
    for (int j = 1; j <= i; j++) {
      f[i] += f[i - j] * g[j];
      if (f[i] > kLim) {
        f[i] = kLim;
        break;
      }
    }
}
bool vis[101];
std::vector<int> Cir(int n, long long k) {
  if (n == 1) return {1};
  std::memset(vis, 0, n);
  std::vector<int> ans(n);
  vis[ans[0] = n - 1] = true;
  auto fd = [&ans](int x) {
    while (ans[x]) x = ans[x];
    return x;
  };
  for (int i = 1; i < n; i++) {
    long long c = g[n - i];
    for (int j = 0; j < n - 1; j++)
      if (!vis[j] && j != i && fd(j) != i) {
        if (k <= c) {
          vis[ans[i] = j] = true;
          break;
        }
        k -= c;
      }
  }
  for (auto &&i : ans) i++;
  return ans;
}
std::vector<int> Dfs(int n, long long k) {
  if (n == 0) return {};
  std::vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (k > g[i] * f[n - i]) {
      k -= g[i] * f[n - i];
      continue;
    }
    long long k1 = (k - 1) / f[n - i] + 1, k2 = (k - 1) % f[n - i] + 1;
    ans = Cir(i, k1);
    std::vector<int> v = Dfs(n - i, k2);
    for (auto &&x : v) x += i;
    ans.insert(ans.end(), v.begin(), v.end());
    break;
  }
  return ans;
}
void Solve() {
  std::cin >> n >> k;
  if (f[n] < k) {
    std::cout << "-1\n";
    return;
  }
  std::cout << Dfs(n, k) << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  Init();
  std::cin >> T;
  while (T--) Solve();
  return 0;
}