#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<int> u(n - 1), v(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
    g[u[i]].push_back(i);
    g[v[i]].push_back(i);
  }
  vector<int> lf;
  for (int i = 0; i < n; ++i) {
    if (g[i].size() == 1) {
      lf.push_back(i);
    }
  }
  if (lf.size() == 2) {
    for (int i = 0; i < n - 1; ++i) cout << i << "\n";
    return 0;
  }
  vector<int> res(n - 1, -1);
  res[g[lf[0]][0]] = 0;
  res[g[lf[1]][0]] = 1;
  res[g[lf[2]][0]] = 2;
  for (int i = 0, k = 3; i < n - 1; ++i) {
    if (res[i] == -1) res[i] = k++;
  }
  for (int i = 0; i < n - 1; ++i) cout << res[i] << "\n";
}