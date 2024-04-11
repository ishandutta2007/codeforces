/**
 *    author:  tourist
 *    created: 28.10.2018 18:37:26       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> res;
  for (int k = 1; k <= n; k++) {
    int ok = 1;
    for (int i = k + 1; i <= n; i++) {
      if (a[i] - a[i - 1] != a[i - k] - a[i - k - 1]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      res.push_back(k);
    }
  }
  cout << (int) res.size() << '\n';
  for (int i = 0; i < (int) res.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << res[i];
  }
  cout << '\n';
  return 0;
}