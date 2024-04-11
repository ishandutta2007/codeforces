#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int x = 0;
  vector<int> ans;
  for (int i = m; i > 0; i--) {
    int y = i & (-i);
    if (x + y <= n) {
      x += y;
      ans.push_back(i);
    }
  }
  if (x != n) {
    cout << -1 << '\n';
    return 0;
  }
  cout << (int) ans.size() << '\n';
  for (int i : ans) {
    cout << i << " ";
  }
  return 0;
}