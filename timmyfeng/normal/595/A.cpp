#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int a[N][2 * N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2 * m; ++j) {
      cin >> a[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans += (a[i][2 * j] | a[i][2 * j + 1]);
    }
  }

  cout << ans << "\n";
}