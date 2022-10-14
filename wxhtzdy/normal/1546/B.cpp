#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<char> ans(m);
  for(int i = 0; i < 2 * n - 1; i++) {
    std::string s;
    std::cin >> s;
    for(int j = 0; j < m; j++) {
      ans[j] ^= s[j];
    }
  }
  for(int i = 0; i < m; i++)
    std::cout << ans[i];
  std::cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}