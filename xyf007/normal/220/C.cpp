#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
int n, a[100001], b[100001];
std::multiset<int> s;
void checkmin(int &x, int y) {
  if (x > y) {
    x = y;
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  int x;
  for (int i = 1; i <= n; i++) {
    std::cin >> x;
    a[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    s.emplace(i - a[b[i]]);
  }
  for (int i = 0; i < n; i++) {
    auto it = s.lower_bound(i);
    int ans = 0x7fffffff;
    if (it != s.end()) {
      checkmin(ans, *it - i);
    }
    if (it != s.begin()) {
      checkmin(ans, i - *--it);
    }
    std::cout << ans << '\n';
    x = b[i + 1];
    s.erase(s.find(i + 1 - a[x]));
    s.emplace(i + 1 + n - a[x]);
  }
  return 0;
}