#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  vector<pair<int, int>> foo;
  for (int i = 0; i < n; i++) {
    foo.emplace_back(a[i], 0);
  }
  for (int i = 0; i < m; i++) {
    foo.emplace_back(b[i], 1);
  }
  sort(foo.begin(), foo.end());
  pair<int, int> ans = {n * 3, n * 3 - m * 3};
  vector<int> cnt(2);
  for (int i = 0; i < (int) foo.size(); i++) {
    cnt[foo[i].second] += 1;
    int new_a = (n - cnt[0]) * 3 + cnt[0] * 2;
    int new_b = new_a - (m - cnt[1]) * 3 - cnt[1] * 2;
    if (ans.second < new_b) {
      ans = make_pair(new_a, new_b);
    } else {
      if (ans.second == new_b) {
        ans = max(ans, make_pair(new_a, new_b));
      }
    }
  }
  cout << ans.first << ":" << ans.first - ans.second << '\n';
  return 0;
}