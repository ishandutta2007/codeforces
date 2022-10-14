#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int x = 0;
  vector<int> ans(1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) x++;
    if (x == 3) {
      ans.push_back(0);
      x = 1;
    }
    ans[ans.size() - 1]++;
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}