#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  multiset<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    s.insert({x, 1});
    s.insert({y, -1});
  }
  int bal = 0;
  pair<int, int> ans;
  ans.first = -1;
  ans.second = -1;
  for (auto e : s) {
    bal += e.second;
    if (ans.second < bal) {
      ans.first = e.first;
      ans.second = bal;
    }
  }
  cout << ans.first << " " << ans.second << '\n';
  return 0;
}