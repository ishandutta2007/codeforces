#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 1;

int max_sim[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i] == t[j]) {
        max_sim[i + 1][j + 1] = max(max_sim[i + 1][j + 1], max_sim[i][j] + 2);
      }
      max_sim[i + 1][j] = max(max_sim[i + 1][j], max_sim[i][j] - 1);
      max_sim[i][j + 1] = max(max_sim[i][j + 1], max_sim[i][j] - 1);
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      ans = max(ans, max_sim[i][j]);
    }
  }

  cout << ans << "\n";
}