/**
 *    author:  wxhtzdy
 *    created: 15.06.2022 19:18:28
**/
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
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return (a[i] < a[j] || (a[i] == a[j] && i < j));
  });
  vector<pair<int, int>> ans;
  while (true) {
    bool found = false;
    for (int i = 0; i < n - 1; i++) {
      if (order[i] > order[i + 1]) {
        swap(order[i], order[i + 1]);
        ans.emplace_back(order[i], order[i + 1]);
        found = true;
      }
    }
    if (!found) {
      break;
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
  }                                                     
  return 0;
}