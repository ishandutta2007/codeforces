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
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) {
        pos.push_back(i);
      }
    }
    int ans = 0;
    for (int i = 0; i < (int) pos.size() - 1; i++) {
      ans += pos[i + 1] - pos[i] - 1;
    }
    cout << ans << '\n';
  }
  return 0;
}