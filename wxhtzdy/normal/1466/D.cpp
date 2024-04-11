/**
 *  author: milos
 *  created: 31.12.2020 02:23:39
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
    }
    vector<int> deg(n, 0);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      deg[u]++;
      deg[v]++;
    }
    long long ans = 0;
    vector<int> b;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < deg[i] - 1; j++) {
        b.push_back(a[i]);
      }
      ans += a[i];
    }
    sort(b.rbegin(), b.rend());
    cout << ans << " ";
    for (int i = 0; i < (int) b.size(); i++) {
      ans += b[i];
      cout << ans << " ";
    }
    cout << '\n';
  }
  return 0;
}