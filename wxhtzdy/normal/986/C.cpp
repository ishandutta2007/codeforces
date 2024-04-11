/**
 *    author:  wxhtzdy
 *    created: 30.05.2022 06:28:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  map<int, int> mp;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    mp[a[i]] = i;
  }
  int k = (1 << n) + m;
  int ans = 0;
  vector<bool> was(k);     
  function<void(int)> Bfs = [&](int x) {
    vector<int> que(1, x);    
    was[x] = true;
    for (int b = 0; b < que.size(); b++) {
      int i = que[b];
      if (i >= m) {
        int v = i - m;             
        for (int j = 0; j < n; j++) {
          if (!(v >> j & 1) && !was[i + (1 << j)]) {
            was[i + (1 << j)] = true;
            que.push_back(i + (1 << j));
          }
        }
        if (mp.count((1 << n) - 1 - v)) {
          int id = mp[(1 << n) - 1 - v];
          if (!was[id]) {
            was[id] = true;
            que.push_back(id);
          }
        }
      } else {
        if (!was[m + a[i]]) {
          was[m + a[i]] = true;
          que.push_back(m + a[i]);
        }
      }
    }
  };
  for (int i = 0; i < m; i++) {
    if (!was[i]) {
      Bfs(i);
      ans += 1;
    }
  }
  cout << ans << '\n';               
  return 0;
}