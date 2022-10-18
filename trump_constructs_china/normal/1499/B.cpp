#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int t, pre[101], nxt[101];
size_t n;
char s[101];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> t;
  while (t--) {
    std::cin >> (s + 1);
    n = std::strlen(s + 1);
    int l0 = -10, l1 = -10;
    for (size_t i = 1; i <= n; i++) {
      if (s[i] == '0') {
        pre[i] = l0;
        l0 = i;
      } else {
        pre[i] = l1;
        l1 = i;
      }
    }
    l0 = n + 10;
    l1 = n + 10;
    for (int i = n; i >= 1; i--) {
      if (s[i] == '0') {
        nxt[i] = l0;
        l0 = i;
      } else {
        nxt[i] = l1;
        l1 = i;
      }
    }
    bool ok = false;
    for (size_t i = 0; i <= n; i++) {
      bool f = true;
      for (size_t j = 1; j <= i && f; j++) {
        if (s[j] == '1') {
          f &= pre[j] < static_cast<int>(j - 1);
        }
      }
      for (size_t j = i + 1; j <= n && f; j++) {
        if (s[j] == '0') {
          f &= nxt[j] > static_cast<int>(j + 1);
        }
      }
      if (f) {
        std::cout << "YES\n";
        ok = true;
        break;
      }
    }
    if (!ok) {
      std::cout << "NO\n";
    }
  }
  return 0;
}