/**
 *    author:  tourist
 *    created: 17.12.2019 18:18:33       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> bal(n);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    bal[x] -= z;
    bal[y] += z;
  }
  vector<pair<int, long long>> p;
  for (int i = 0; i < n; i++) {
    if (bal[i] < 0) {
      p.emplace_back(i, -bal[i]);
    }
  }
  vector<tuple<int, int, long long>> ret;
  for (int i = 0; i < n; i++) {
    while (bal[i] > 0) {
      long long val = min(bal[i], p.back().second);
      ret.emplace_back(p.back().first, i, val);
      bal[i] -= val;
      p.back().second -= val;
      if (p.back().second == 0) {
        p.pop_back();
      }
    }
  }
  cout << ret.size() << '\n';
  for (auto& p : ret) {
    cout << get<0>(p) + 1 << " " << get<1>(p) + 1 << " " << get<2>(p) << '\n';
  }
  return 0;
}