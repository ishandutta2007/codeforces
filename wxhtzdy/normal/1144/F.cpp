#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> x(m), y(m);
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i];
    x[i]--, y[i]--;
    g[x[i]].push_back(y[i]);
    g[y[i]].push_back(x[i]);
  }
  vector<int> col(n);
  vector<int> q;
  vector<bool> was(n, false);
  q.push_back(0);
  was[0] = true;
  for (int i = 0; i < (int) q.size(); i++) {
    int r = q[i];
    for (int c : g[r]) {
      if (was[c]) {
        if (col[c] == col[r]) {
          cout << "NO" << '\n';
          return 0;
        }
      } else {
        was[c] = 1;
        col[c] = 1 - col[r];
        q.push_back(c);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (col[x[i]] == col[y[i]]) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  for (int i = 0; i < m; i++) {
    cout << col[y[i]];
  }
  return 0;
}