#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<int> cnt(31, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < 31; j++) {
      if (a[i] == (1 << j)) {
        cnt[j] += 1;
      }
    }
  }
  while (q--) {
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
      int tmp = min(x / (1 << i), cnt[i]);
      x -= tmp * (1 << i);
      ans += tmp;
    }
    cout << (x == 0 ? ans : -1) << '\n';
  }
  return 0;
}