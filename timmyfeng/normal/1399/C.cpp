#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> w(n);
    for (auto& i : w) {
      cin >> i;
    }
    sort(w.begin(), w.end());

    int ans = 0;
    for (int i = 2; i <= 2 * n; ++i) {
      int cnt = 0;
      int r = n - 1;
      for (int l = 0; l < r; ++l) {
        while (r > l + 1 && w[l] + w[r] > i) {
          --r;
        }
        if (w[l] + w[r] == i) {
          ++cnt;
          --r;
        }
      }
      ans = max(ans, cnt);
    }
    cout << ans << "\n";
  }
}