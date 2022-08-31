/**
 *    author:  tourist
 *    created: 29.05.2018 19:13:49       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> was(1 << n, 1);
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    was[x] = 0;
  }
  vector<int> used(1 << n, 0);
  vector<int> que(1 << n);
  vector<int> inner(1 << n);
  int ans = 0;
  for (int start = 0; start < (1 << n); start++) {
    if (was[start]) {
      continue;
    }
    ans++;
    was[start] = 1;
    que[0] = start;
    int qs = 1;
    for (int q = 0; q < qs; q++) {
      int u = (1 << n) - 1 - que[q];
      if (!used[u]) {
        used[u] = 1;
        inner[0] = u;
        int is = 1;
        for (int i = 0; i < is; i++) {
          int z = inner[i];
          if (!was[z]) {
            was[z] = 1;
            que[qs++] = z;
          }
          for (int bit = 0; bit < n; bit++) {
            if ((z & (1 << bit)) && !used[z ^ (1 << bit)]) {
              used[z ^ (1 << bit)] = 1;
              inner[is++] = z ^ (1 << bit);
            }
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}