/**
 *  author: milos
 *  created: 13.12.2020 16:40:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, x, y;
  cin >> n >> x >> y;
  if (y < n) {
    cout << -1 << '\n';
    return 0;
  }
  vector<long long> ans;
  ans.push_back(y - n + 1);
  for (int i = 0; i < n - 1; i++) {
    ans.push_back(1);
  }
  long long sum = 0;
  for (int i = 0; i < (int) ans.size(); i++) {
    sum += ans[i] * ans[i];
  }
  if (sum < x) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}