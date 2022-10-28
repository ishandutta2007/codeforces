#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& i : grid) {
      cin >> i;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      ans += (grid[i][m - 1] != 'D');
    }
    for (int i = 0; i < m -1; ++i) {
      ans += (grid[n - 1][i] != 'R');
    }
    cout << ans << "\n";
  }
}