/**
 *    author:  tourist
 *    created: 30.07.2019 17:43:32       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(3 * n);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].emplace_back(y, i);
      g[y].emplace_back(x, i);
    }
    vector<int> used(3 * n);
    vector<int> mat;
    for (int i = 0; i < 3 * n; i++) {
      if (used[i]) {
        continue;
      }
      for (auto& p : g[i]) {
        if (!used[p.first]) {
          mat.push_back(p.second);
          used[i] = used[p.first] = 1;
          break;
        }
      }
    }
    if ((int) mat.size() >= n) {
      cout << "Matching" << '\n';
      for (int i = 0; i < n; i++) {
        if (i > 0) {
          cout << " ";
        }
        cout << mat[i] + 1;
      }
      cout << '\n';
    } else {
      cout << "IndSet" << '\n';
      int cnt = 0;
      for (int i = 0; i < 3 * n; i++) {
        if (used[i]) {
          continue;
        }
        if (cnt > 0) {
          cout << " ";
        }
        cout << i + 1;
        ++cnt;
        if (cnt == n) {
          break;
        }
      }
      cout << '\n';
    }
  }
  return 0;
}