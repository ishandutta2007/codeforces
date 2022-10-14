/**
 *  author: milos
 *  created: 08.01.2021 19:02:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }             
  int k = (int) (1 << (m));
  auto Can = [&](int x) {
    vector<int> cnt(2 * k + 1, 0);
    for (int i = 0; i < n; i++) {
      int mask = 0;
      for (int j = 0; j < m; j++) {
        if (a[i][j] >= x) {
          mask += (int) (1 << j);
        }
      }
      for (int j = 0; j < 2 * k + 1; j++) {
        if ((j | mask) >= k - 1 && cnt[j] > 0) {
          return make_pair(cnt[j], i + 1);  
        }
      }
      cnt[mask] = i + 1;
    }
    return make_pair(0, 0);
  };
  int bot = 0, top = 1e9, val = 0;
  pair<int, int> ans;
  ans.first = 1;
  ans.second = 1;
  while (bot <= top) {
    int mid = bot + top >> 1;
    pair<int, int> ret = Can(mid);
    if (ret.first != 0) {
      ans = ret;
      val = mid;
      bot = mid + 1;  
    } else {
      top = mid - 1;
    }
  }
  cout << ans.first << " " << ans.second << '\n';
  return 0;
}