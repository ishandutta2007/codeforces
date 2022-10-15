#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    std::string S;
    std::cin >> S;
    int cnt[2]{};
    for (int c : S) {
      c -= '0';
      ++cnt[c];
    }
    int res = cnt[0] == cnt[1] ? cnt[0] - 1 : std::min(cnt[0], cnt[1]);
    std::cout << res << '\n';
  }
  exit(0);
}