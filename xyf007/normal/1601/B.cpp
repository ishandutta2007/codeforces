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
struct Node {
  int a, b, id;
} a[300001];
int n, nxt[300001];
std::vector<int> pre[300001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i].a;
  for (int i = 1; i <= n; i++) std::cin >> a[i].b, a[i].id = i;
  for (int i = 1; i <= n; i++) pre[a[i].id + a[i].b].emplace_back(i);
  std::sort(a + 1, a + n + 1, [](const Node &lhs, const Node &rhs) {
    return lhs.id - lhs.a < rhs.id - rhs.a;
  });
  std::memset(nxt, -1, sizeof(nxt));
  int las = 0, p = 1;
  bool f = true;
  while (f) {
    f = false;
    int nlas = 0;
    while (p <= n && a[p].id - a[p].a <= las) {
      nxt[a[p].id] = las;
      f = true;
      for (auto &&x : pre[a[p].id]) checkmax(nlas, x);
      p++;
    }
    las = nlas;
  }
  std::sort(a + 1, a + n + 1,
            [](const Node &lhs, const Node &rhs) { return lhs.id < rhs.id; });
  if (nxt[n] == -1) {
    std::cout << -1;
    return 0;
  }
  std::vector<int> ans;
  for (int i = nxt[n]; i; i = nxt[i]) ans.emplace_back(i), i += a[i].b;
  ans.emplace_back(0);
  std::cout << ans.size() << '\n';
  for (auto &&x : ans) std::cout << x << ' ';
  return 0;
}