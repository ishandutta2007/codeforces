#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> all(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    all[a].push_back(b);
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j : all[i]) {
      if (j < mx) {
        cout << "Happy Alex" << '\n';
        return 0;
      }
    }
    for (int j : all[i]) {
      mx = max(mx, j);
    }
  }
  cout << "Poor Alex" << '\n';
  return 0;
}