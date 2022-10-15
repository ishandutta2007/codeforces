#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
int n, m, a[101][10001], pre[101][10001], nxt[101][10001];
char s[101][10001];
std::vector<int> v;
void checkmin(int &x, int y) {
  if (x > y) {
    x = y;
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> (s[i] + 1);
    std::vector<int>().swap(v);
    v.emplace_back(0);
    for (int j = 1; j <= m; j++) {
      a[i][j] = s[i][j] - '0';
      if (a[i][j]) {
        v.emplace_back(j);
      }
    }
    if (v.size() == 1) {
      std::cout << -1;
      return 0;
    }
    v.emplace_back(m + v.at(1));
    for (size_t j = 0; j < v.size() - 1; j++) {
      for (int k = v.at(j) + 1; k <= v.at(j + 1) && k <= m; k++) {
        nxt[i][k] = v.at(j + 1);
      }
    }
    v.back() = m + 1;
    v.front() = v.at(v.size() - 2) - m;
    for (size_t j = v.size() - 1; j >= 1; j--) {
      for (int k = v.at(j) - 1; k >= v.at(j - 1) && k; k--) {
        pre[i][k] = v.at(j - 1);
      }
    }
  }
  int ans = 0x7fffffff;
  for (int j = 1; j <= m; j++) {
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
      tmp += std::min(j - pre[i][j], nxt[i][j] - j);
    }
    checkmin(ans, tmp);
  }
  std::cout << ans;
  return 0;
}