#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  vector<vector<int>> day(m);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    --d[i];
    if (d[i] >= 0) {
      day[d[i]].push_back(i);
    }
  }
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  auto Check = [&](int x) {
    vector<int> b;
    for (int i = 0; i < m; i++) {
      if (day[i].empty() || day[i][0] > x) {
        return false;
      }
      int pos = lower_bound(day[i].begin(), day[i].end(), x + 1) - day[i].begin();
      assert(pos > 0);
      pos -= 1;
      b.push_back(day[i][pos]);
    }
    assert(b.size() == m);
    vector<int> id(n, -1);
    for (int i = 0; i < m; i++) {
      id[b[i]] = i;
    }
    int cnt = 0, cc = m;
    for (int i = 0; i <= x; i++) {
      if (id[i] == -1) {
        cnt += 1;
      } else {
        if (cnt < a[id[i]]) {
          return false;
        }
        cc -= 1;
        cnt -= a[id[i]];
      }
    }
    return cc == 0;
  };
  if (!Check(n - 1)) {
    cout << -1 << '\n';
    return 0;
  }
  int low = 0, high = n - 1, ans = 0;
  while (low <= high) {
    int mid = low + high >> 1;
    if (Check(mid)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << ans + 1 << '\n';
  return 0;
}