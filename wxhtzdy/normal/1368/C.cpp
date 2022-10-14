#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> p;
  p.emplace_back(0, 0);
  p.emplace_back(1, 0);
  for (int i = 0; i < n; i++) {
    p.emplace_back(i, i + 1);
    p.emplace_back(i + 1, i + 1);
    p.emplace_back(i + 2, i + 1);
  }
  p.emplace_back(n, n + 1);
  p.emplace_back(n + 1, n + 1);
  cout << (int) p.size() << '\n';
  for (int i = 0; i < (int) p.size(); i++) {
    cout << p[i].first << " " << p[i].second << '\n';
  }
  return 0;
}