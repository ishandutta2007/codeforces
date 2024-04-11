/**
 *    author:  milos
 *    created: 23.03.2021 09:57:52       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  long long s = 0;
  for (int i = 0; i < n - 1; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x, --y;
    g[x].emplace_back(y, z);
    g[y].emplace_back(x, z);
    s += z;
  }
  vector<long long> dist(n, -1);
  vector<int> q(1, 0);
  dist[0] = 0;
  for (int b = 0; b < (int) q.size(); b++) {
    for (auto j : g[q[b]]) {
      if (dist[j.first] == -1) {
        dist[j.first] = dist[q[b]] + j.second;
        q.push_back(j.first);
      }
    }
  }
  long long ans = 2 * s;
  for (int i = 0; i < n; i++) {
    ans = min(ans, 2 * s - dist[i]);
  }
  cout << ans << '\n';
  return 0;
}