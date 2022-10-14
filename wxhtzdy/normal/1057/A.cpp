/**
 *  author: milos
 *  created: 15.01.2021 01:51:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  vector<int> ans;
  ans.push_back(n - 1);
  int x = n - 1;
  while (x != 0) {
    x = a[x];
    ans.push_back(x);
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i] + 1;
  }
  return 0;
}