#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    for (int i = 0;  i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = min(a[i][j], a[i][u] + w + a[v][j]);
        a[i][j] = min(a[i][j], a[i][v] + w + a[u][j]);
      }
    }
    long long ans = 0;
    for (int i = 0;  i < n; i++) {
      for (int j = i; j < n; j++) {
        ans += a[i][j];
      }
    }
    cout << ans << ' ';
  }
  return 0;
}