#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]] += 1;
  }
  pair<int, int> mx;
  mx.first = mx.second = 0;
  for (auto c : cnt) {
    if (c.second >= mx.first) {
      mx.first = c.second;
      mx.second = c.first;
    }
  }
  int x = mx.second;
  vector<int> pos;
  pos.push_back(-1);
  for (int i = 0; i < n; i++) {
    if (a[i] == x) {
      pos.push_back(i);
    }
  }
  vector<tuple<int, int, int>> ans;
  for (int i = 1; i < (int) pos.size(); i++) {
    for (int j = pos[i] - 1; j > pos[i - 1]; j--) {
      int foo;
      if (a[j] <= x) {
        foo = 1;
      } else {
        foo = 2;
      }
      ans.push_back({foo, j + 1, j + 2});
    }
  }
  for (int i = pos.back(); i < n - 1; i++) {
    int foo;
    if (a[i + 1] <= x) {
      foo = 1;
    } else {
      foo = 2;
    }
    ans.push_back({foo, i + 2, i + 1});
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << '\n';
  }
  return 0;
}