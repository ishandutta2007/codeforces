#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string S;
  std::cin >> S;
  int N = S.size();
  std::vector<int> pref(N), suff(N);
  for (int i = 0; i + 1 < N; ++i) {
    pref[i + 1] = pref[i] + (S.substr(i, 2) == "vv");
  }
  for (int i = N - 2; i >= 0; --i) {
    suff[i] = suff[i + 1] + (S.substr(i, 2) == "vv");
  }
  int64_t ans = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'o') {
      ans += 1LL * pref[i] * suff[i];
    }
  }
  std::cout << ans << '\n';
  exit(0);
}