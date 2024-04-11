#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int t, h, m, rev[] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
char s[101];
bool Check(int c) { return c == 0 || c == 1 || c == 2 || c == 5 || c == 8; }
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> t;
  while (t--) {
    std::cin >> h >> m >> s;
    int nh = (s[0] - '0') * 10 + s[1] - '0',
        nm = (s[3] - '0') * 10 + s[4] - '0';
    bool f = false;
    for (int i = nh; i < h && !f; i++) {
      for (int j = i == nh ? nm : 0; j < m && !f; j++) {
        if (!Check(i % 10) || !Check(i / 10) || !Check(j % 10) ||
            !Check(j / 10)) {
          continue;
        }
        int th = rev[j % 10] * 10 + rev[j / 10],
            tm = rev[i % 10] * 10 + rev[i / 10];
        if (th < h && tm < m) {
          f = true;
          std::cout << std::setw(2) << std::setfill('0') << i << ':'
                    << std::setw(2) << std::setfill('0') << j << '\n';
          break;
        }
      }
    }
    if (!f) {
      std::cout << "00:00\n";
    }
  }
  return 0;
}