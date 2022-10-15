#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N, K;
    std::cin >> N >> K;
    std::string S;
    std::cin >> S;
    bool palindrome = std::equal(S.begin(), S.end(), S.rbegin(), S.rend());
    int res = palindrome ? 1 : 1 + !!K;
    std::cout << res << '\n';
  }
  exit(0);
}