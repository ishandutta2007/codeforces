#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> spells;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    spells.emplace_back(a, 0);
  }

  int cur = 0;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      ++cur;
      if (b < 1e9) {
        spells.emplace_back(b, 1);
      }
    }
  }
  sort(spells.begin(), spells.end());

  int ans = cur;
  for (auto [i, j] : spells) {
    if (j == 1) {
      --cur;
    } else {
      ++cur;
    }
    ans = min(ans, cur);
  }
  cout << ans << "\n";
}