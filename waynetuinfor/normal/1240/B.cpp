#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> ds(a.begin(), a.end());
    sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i < n; ++i) {
      a[i] = lower_bound(ds.begin(), ds.end(), a[i]) - ds.begin();
    }
    int m = ds.size();
    vector<vector<int>> pos(m, {n, -1});
    for (int i = 0; i < n; ++i) {
      pos[a[i]][0] = min(pos[a[i]][0], i);
      pos[a[i]][1] = max(pos[a[i]][1], i);
    }
    vector<bool> good(m, false);
    for (int i = 0; i + 1 < m; ++i) {
      if (pos[i][1] < pos[i + 1][0]) good[i] = true;
    }
    int ans = 0;
    for (int i = 0, j = 0; i < m - 1; i = j) {
      if (!good[i]) {
        j++;
        continue;
      }
      while (j < m - 1 && good[j]) j++;
      ans = max(ans, j - i);
    }
    cout << m - ans - 1 << "\n";
  }
}