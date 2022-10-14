#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, l;
    cin >> n >> l;
    vector<vector<int>> cnt(l, vector<int>(2));
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < l; j++) {
        if (x & (1 << j)) {
          cnt[j][1] += 1;
        } else {
          cnt[j][0] += 1;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < l; i++) {
      if (cnt[i][1] > cnt[i][0]) {
        ans += (1 << i);
      }
    }
    cout << ans << '\n';
  }
}