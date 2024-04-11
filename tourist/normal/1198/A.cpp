/**
 *    author:  tourist
 *    created: 30.07.2019 17:32:42       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, sz;
  cin >> n >> sz;
  sz *= 8;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int k = sz / n;
  int values = (k < 30 ? (1 << k) : n);
  int ans = 0;
  int r = 0;
  int diff = 0;
  for (int i = 0; i < n; i++) {
    while (r < n) {
      if (r > i && a[r] == a[r - 1]) {
        ++r;
      } else {
        if (diff == values) {
          break;
        }
        ++diff;
        ++r;
      }
    }
    ans = max(ans, r - i);
    if (i < n - 1 && (i + 1 == r || a[i] != a[i + 1])) {
      --diff;
    }
  }
  cout << n - ans << '\n';
  return 0;
}