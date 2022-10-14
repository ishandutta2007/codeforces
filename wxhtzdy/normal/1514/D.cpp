#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, qq;
  cin >> n >> qq;
  vector<int> a(n);
  vector<vector<int>> pos(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  mt19937 rng(time(0));
  while (qq--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int need = (r - l + 1) / 2, occ = -1;
    for (int i = 0; i < 30; i++) {
      int sz = r - l + 1;
      int where = l + rng() % sz;
      int val = a[where];
      int cnt = lower_bound(pos[val].begin(), pos[val].end(), r + 1) - lower_bound(pos[val].begin(), pos[val].end(), l);
      if (cnt >= need) {
        occ = cnt;
        break;
      }
    }
    if (occ == -1) {
      cout << 1 << '\n';
    } else {
      cout << max(1, occ * 2 - (r - l + 1)) << '\n';
    }
  }
  return 0;
}