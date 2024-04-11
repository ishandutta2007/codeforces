/**
 *    author:  milos
 *    created: 12.09.2021 10:15:20       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {      
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }      
  const int LOG = 20;
  vector<vector<int>> mx(n, vector<int>(LOG));
  vector<vector<int>> mn(n, vector<int>(LOG));
  for (int i = 0; i < n; i++) {
    mx[i][0] = a[i];
    mn[i][0] = a[i];
  }
  for (int j = 1; j < LOG; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
    }
  }
  vector<int> logs(n + 1);
  logs[0] = 0;
  logs[1] = 0;
  for (int i = 2; i <= n; i++) {
    logs[i] = logs[i / 2] + 1;
  }
  auto getMax = [&](int l, int r) {
    int k = logs[r - l + 1];
    return max(mx[l][k], mx[r - (1 << k) + 1][k]);
  };
  auto getMin = [&](int l, int r) {
    int k = logs[r - l + 1];
    return min(mn[l][k], mn[r - (1 << k) + 1][k]);
  };
  int len;
  int bot = 1, top = n;
  while (bot <= top) {
    int mid = bot + top >> 1;
    bool ok = false;
    for (int i = 0; i + mid <= n; i++) {
      if (getMax(i, i + mid - 1) <= getMin(i, i + mid - 1) + k) {
        ok = true;
        break;
      }
    }
    if (ok) {
      len = mid;
      bot = mid + 1; 
    } else {
      top = mid - 1;
    }
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i + len <= n; i++) {
    if (getMax(i, i + len - 1) <= getMin(i, i + len - 1) + k) {
      ans.push_back({i, i + len - 1});
    }
  }
  cout << len << " " << ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
  }
  return 0;
}