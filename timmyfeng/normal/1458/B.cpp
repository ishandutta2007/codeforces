#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int cap[N][N][N * N], a[N], b[N];

void set_max(int &a, int b) {
  if (b > a) {
    a = b;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(11);

  int n;
  cin >> n;

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    sum += b[i];
  }

  for (int i = 0; i <= n; ++i) {
    for (int k = 0; k <= n; ++k) {
      for (int j = 0; j <= sum; ++j) {
        cap[i][k][j] = -1;
      }
    }
  }
  cap[0][0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < n; ++k) {
      for (int j = 0; j <= sum; ++j) {
        if (cap[i][k][j] != -1) {
          set_max(cap[i + 1][k][j], cap[i][k][j]);
          set_max(cap[i + 1][k + 1][j + b[i]], cap[i][k][j] + a[i]);
        }
      }
    }
  }

  for (int k = 1; k <= n; ++k) {
    double ans = 0.0;
    for (int i = 0; i <= sum; ++i) {
      ans = max(ans, min((double) cap[n][k][i], 0.5 * (sum - i) + i));
    }
    cout << ans << " ";
  }
}