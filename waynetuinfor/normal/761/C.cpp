#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;
int n, m, d[3][maxn], ans;
string s[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < n; ++i) {
    d[0][i] = d[1][i] = d[2][i] = (1 << 20);
    for (int j = 0; j < m; ++j) {
      if (s[i][j] <= '9' && s[i][j] >= '0') d[0][i] = min({ d[0][i], j, m - j });
      if (s[i][j] >= 'a' && s[i][j] <= 'z') d[1][i] = min({ d[1][i], j, m - j });
      if (s[i][j] == '#' || s[i][j] == '*' || s[i][j] == '&') d[2][i] = min({ d[2][i], j, m - j });
    }
  }
  ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) if (i != j) {
      for (int k = 0; k < n; ++k) if (j != k) {
        ans = min(ans, d[0][i] + d[1][j] + d[2][k]);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}