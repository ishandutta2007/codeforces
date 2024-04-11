/**
 *    author:  tourist
 *    created: 14.09.2019 16:05:14       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int ok = 0;
    for (int j = 0; j < i; j++) {
      if (a[i] % a[j] == 0) {
        ok = 1;
        break;
      }
    }
    if (!ok) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}