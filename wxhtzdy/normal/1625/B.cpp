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
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) {
      pos[a[i]].push_back(i);
    }
    int ans = -1;
    for (auto p : pos) {
      vector<int> v = p.second;
      for (int i = 0; i + 1 < (int) v.size(); i++) {
        ans = max(ans, n - (v[i + 1] - v[i]));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}