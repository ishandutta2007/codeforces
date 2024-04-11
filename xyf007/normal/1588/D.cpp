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
int T, n, nxt[11][115][52], pos[52];
char s[11][115];
std::map<std::vector<int>, int> mp;
std::map<std::vector<int>, int> ntt;
int Dfs(const std::vector<int> &v) {
  if (mp.count(v)) return mp[v];
  int &ans = mp[v];
  for (int i = 0; i < 52; i++) {
    bool f = true;
    for (int j = 0; j < n; j++)
      if (nxt[j][v[j]][i] > 200) {
        f = false;
        break;
      }
    if (f) {
      std::vector<int> vv(n);
      for (int j = 0; j < n; j++) vv[j] = nxt[j][v[j]][i];
      if (int tmp = Dfs(vv); tmp + 1 > ans) ans = tmp + 1, ntt[v] = i;
    }
  }
  return ans;
}
void Solve() {
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> (s[i] + 1);
  for (int i = 0; i < n; i++) {
    int l = std::strlen(s[i] + 1);
    for (int j = 1; j <= l; j++)
      if (std::isupper(s[i][j]))
        s[i][j] -= 'A';
      else
        s[i][j] -= 'a' - 26;
    std::memset(nxt[i], 0x3f, sizeof(nxt[i]));
    std::memset(pos, 0x3f, sizeof(pos));
    for (int j = l - 1; j >= 0; j--) {
      pos[s[i][j + 1]] = j + 1;
      std::memcpy(nxt[i][j], pos, sizeof(pos));
    }
  }
  std::map<std::vector<int>, int>().swap(mp);
  std::map<std::vector<int>, int>().swap(ntt);
  std::vector<int> st(n);
  std::cout << Dfs(st) << '\n';
  while (ntt.count(st)) {
    int v = ntt[st];
    std::cout << static_cast<char>(v < 26 ? v + 'A' : v - 26 + 'a');
    for (int i = 0; i < n; i++) st[i] = nxt[i][st[i]][v];
  }
  std::cout << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}