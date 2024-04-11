#include <bits/stdc++.h>
using namespace std;

const int N = 80 + 2;

int dp[N][N][N * N];
int len[N];
int a[N];

int choose2(int n) {
  return n * (n - 1) / 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int m = 0;
  for (int i = 0, j = 0; i <= n; i = j) {
    while (j < n && a[j] != 1) {
      ++j;
    }
    len[m] = j - i + (m == 0 ? 0 : len[m - 1]);
    ++j, ++m;
  }

  int zeroes = count(a, a + n, 0);
  dp[0][0][0] = choose2(zeroes);

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j <= zeroes; ++j) {
      for (int jj = j; jj <= zeroes; ++jj) {
        for (int k = 0; k <= choose2(n) - abs(len[i] - jj); ++k) {
          int kk = k + abs(len[i] - jj);
          dp[i + 1][jj][kk] = max(dp[i + 1][jj][kk], dp[i][j][k] - choose2(jj - j));
        }
      }
    }
  }

  int max_s = 0;
  for (int i = 0; i <= choose2(n); ++i) {
    max_s = max(max_s, dp[m][zeroes][i]);
    cout << max_s << " ";
  }
  cout << "\n";
}