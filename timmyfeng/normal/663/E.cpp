#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int mask[1 << N], diff[N][1 << N], sum[2][1 << N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == '1') {
        mask[j] ^= 1 << i;
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    ++diff[0][mask[i]];
  }

  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      sum[0][i][j] = diff[0][i];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      for (int k = 0; k < n; ++k) {
        diff[i][j] += sum[1 - i % 2][j ^ (1 << k)][k];
      }
      diff[i][j] /= i;
      for (int k = 0; k < n; ++k) {
        sum[i % 2][j][k] = diff[i][j] - sum[1 - i % 2][j ^ (1 << k)][k];
      }
    }
  }

  int ans = n * m;
  for (int i = 0; i < (1 << n); ++i) {
    int res = 0;
    for (int j = 0; j <= n; ++j) {
      res += min(j, n - j) * diff[j][i];
    }
    ans = min(ans, res);
  }

  cout << ans << "\n";
}