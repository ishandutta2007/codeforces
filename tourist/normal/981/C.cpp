/**
 *    author:  tourist
 *    created: 27.05.2018 17:55:04       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> deg(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    deg[x]++;
    deg[y]++;
  }
  vector<vector<int>> by_deg(n + 1);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    by_deg[deg[i]].push_back(i);
    mx = max(mx, deg[i]);
  }
  if (mx <= 2) {
    cout << "Yes" << '\n';
    cout << 1 << '\n';
    cout << by_deg[1][0] + 1 << " " << by_deg[1][1] + 1 << '\n';
    return 0;
  }
  int cc = 0;
  int who = -1;
  for (int i = 0; i < n; i++) {
    if (deg[i] > 2) {
      cc++;
      who = i;
    }
  }
  if (cc > 1) {
    cout << "No" << '\n';
    return 0;
  }
  cout << "Yes" << '\n';
  cout << by_deg[1].size() << '\n';
  for (int i : by_deg[1]) {
    cout << who + 1 << " " << i + 1 << '\n';
  }
  return 0;
}