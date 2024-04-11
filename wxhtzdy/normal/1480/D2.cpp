/**
 *    author:  milos
 *    created: 07.02.2021 16:28:08       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> pos(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  vector<int> id(n + 1, 0);
  int ans = 0;
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      if (a[i] != x && a[i] != y) {
        ans++;
      }
      continue;
    }
    if (a[i] == x) {
      id[x]++;
      continue;
    }
    if (a[i] == y) {
      id[y]++;
      continue;
    }                 
    int xx = (id[x] >= (int) pos[x].size() ? n : pos[x][id[x]]);
    int yy = (id[y] >= (int) pos[y].size() ? n : pos[y][id[y]]);
    //int rr = (id[a[i]] >= (int) pos[a[i]].size() ? n : pos[a[i]][id[a[i]]]);
    if (xx >= yy) {
      x = a[i];
      id[a[i]]++;
      ans++;
      continue;
    } else {
      y = a[i];
      id[a[i]]++;
      ans++;
      continue;
    }
  }
  cout << ans << '\n';
  return 0;
}