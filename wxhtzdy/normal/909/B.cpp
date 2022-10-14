/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 11:08:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<pair<int, int>> ev;
  for (int i = 0; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ev.emplace_back(i, +1);
      ev.emplace_back(j, -1);
    }
  }
  sort(ev.begin(), ev.end());
  int bal = 0, ans = 0;
  for (auto& p : ev) {
    bal += p.second;
    ans = max(ans, bal);
  }
  cout << ans << '\n';                                               
  return 0;
}