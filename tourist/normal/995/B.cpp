/**
 *    author:  tourist
 *    created: 24.11.2020 19:51:19       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
    --a[i];
  }
  int ans = (int) 1e9;
  for (int rot = 0; rot < 1; rot++) {
    auto backup = a;
    int cur = 0;
    for (int i = 0; i < 2 * n; i += 2) {
      for (int j = i + 1; j < 2 * n; j++) {
        if (a[j] == a[i]) {
          for (int k = j; k > i + 1; k--) {
            swap(a[k], a[k - 1]);
            ++cur;
          }
          break;
        }
      }
    }
    ans = min(ans, cur);
    a = backup; 
    rotate(a.begin(), a.begin() + 1, a.end());
  }
  cout << ans << '\n';
  return 0;
}