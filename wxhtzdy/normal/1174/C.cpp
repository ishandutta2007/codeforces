/**
 *  author: milos
 *  created: 04.01.2021 03:31:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ans(n, 0);
  int cnt = 1;
  for (int i = 2; i <= n; i++) {
    bool ok = false;
    for (int j = i; j <= n; j += i) {
      if (ans[j - 1] == 0) {
        ok = true;
        ans[j - 1] = cnt;
      }
    }
    cnt += ok;
  }
  for (int i = 1; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}