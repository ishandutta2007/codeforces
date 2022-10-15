#include <iostream>
#include <utility>
#include <vector>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, a[201], pos[201];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  int now = 0, all = 0;
  for (int i = 1; i <= m; i++) {
    int x;
    std::cin >> x, all += x;
    for (int j = 1; j <= x; j++) std::cin >> pos[++now], a[pos[now]] = now;
  }
  std::vector<std::pair<int, int>> ans;
  for (int i = 1; i <= all; i++) {
    if (a[i] == i) continue;
    if (a[i] == 0) {
      ans.emplace_back(pos[i], i);
      std::swap(a[pos[i]], a[i]), pos[i] = i;
    } else {
      int z = 0;
      for (int j = i + 1; j <= n; j++)
        if (a[j] == 0) {
          z = j;
          break;
        }
      ans.emplace_back(i, z);
      pos[a[i]] = z, std::swap(a[i], a[z]);
      ans.emplace_back(pos[i], i);
      std::swap(a[pos[i]], a[i]), pos[i] = i;
    }
  }
  std::cout << ans.size() << '\n';
  for (const auto &[x, y] : ans) std::cout << x << ' ' << y << '\n';
  return 0;
}