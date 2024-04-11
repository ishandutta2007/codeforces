#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    std::string S;
    std::cin >> S;
    int cnt[26]{};
    for (int c : S) {
      c -= 'a';
      ++cnt[c];
    }
    int i = 0;
    while (true) {
      int c = S[i] - 'a';
      if (cnt[c] == 1) break;
      --cnt[c];
      ++i;
    }
    std::cout << S.substr(i, S.size()) << '\n';
  }
  exit(0);
}