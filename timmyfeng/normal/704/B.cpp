#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 1;

long long x[N], a[N], b[N], c[N], d[N];
long long min_time[N][N];

void set_min(long long &a, long long b) {
  if (b < a) {
    a = b;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s, e;
  cin >> n >> s >> e;

  for (long long *u : {x, a, b, c, d}) {
    for (int i = 0; i < n; ++i) {
      cin >> u[i];
    }
  }

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      min_time[i][j] = LLONG_MAX;
    }
  }
  min_time[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (min_time[i][j] == LLONG_MAX) {
        continue;
      }

      if (i == s - 1) {
        if (j - (e <= i) > 0 || (i == n - 1 && j > 0)) {
          set_min(min_time[i + 1][j], min_time[i][j] + c[i] + x[i]);
        }
        set_min(min_time[i + 1][j + 1], min_time[i][j] + d[i] - x[i]);
      } else if (i == e - 1) {
        if (j - (s <= i) > 0 || (i == n - 1 && j > 0)) {
          set_min(min_time[i + 1][j], min_time[i][j] + a[i] + x[i]);
        }
        set_min(min_time[i + 1][j + 1], min_time[i][j] + b[i] - x[i]);
      } else {
        if (j - (s <= i && e <= i) > 1 || (i == n - 1 && j > 1)) {
          set_min(min_time[i + 1][j - 1], min_time[i][j] + 2 * x[i] + a[i] + c[i]);
        }
        if (j - (s <= i) > 0) {
          set_min(min_time[i + 1][j], min_time[i][j] + b[i] + c[i]);
        }
        if (j - (e <= i) > 0) {
          set_min(min_time[i + 1][j], min_time[i][j] + a[i] + d[i]);
        }
        set_min(min_time[i + 1][j + 1], min_time[i][j] - 2 * x[i] + b[i] + d[i]);
      }
    }
  }

  cout << min_time[n][1] << "\n";
}