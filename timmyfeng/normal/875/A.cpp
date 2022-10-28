#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  set<int> ans;
  for (int i = 0; i <= min(9 * 9, n); ++i) {
    int x = n - i;
    int res = 0;
    int y = x;
    while (y > 0) {
      res += y % 10;
      y /= 10;
    }
    if (res == i) {
      ans.insert(x);
    }
  }

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}