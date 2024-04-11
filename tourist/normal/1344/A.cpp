/**
 *    author:  tourist
 *    created: 06.05.2020 17:32:35       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = ((i + a[i]) % n + n) % n;
    }
    sort(a.begin(), a.end());
    bool ok = true;
    for (int i = 0; i < n; i++) {
      ok &= (a[i] == i);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}