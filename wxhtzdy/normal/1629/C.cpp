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
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pos[a[i]].push_back(i);
    }
    vector<int> b;
    int ptr = 0;
    while (ptr < n) {
      int val = 0, nxt = ptr;
      for (int i = 0; i <= n; i++) {
        auto it = lower_bound(pos[i].begin(), pos[i].end(), ptr);
        if (it == pos[i].end()) {
          val = i;
          break;
        }
        nxt = max(nxt, *it);
      }
      b.push_back(val);
      ptr = nxt + 1;
    }
    cout << b.size() << '\n';
    for (int i = 0; i < b.size(); i++) {
      cout << b[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}