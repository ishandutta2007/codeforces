#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 1;

void set_min(int &a, int b) {
  if (a > b) {
    a = b;
  }
}

int unused[2][N], used[2][N][2];
long long t[N], x[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> t[i] >> x[i];
  }

  for (int i = 0; i <= n; ++i) {
    used[0][i][0] = used[0][i][1] = unused[0][i] = INT_MAX;
  }
  unused[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      used[1 - i % 2][j][0] = used[1 - i % 2][j][1] = unused[1 - i % 2][j] = INT_MAX;
    }

    for (int j = 0; j <= n; ++j) {
      if (unused[i % 2][j] != INT_MAX) {
        for (int k = i + 1; k <= n; ++k) {
          if (unused[i % 2][j] + abs(x[k] - x[j]) <= t[i + 1]) {
            set_min(used[i % 2][k][1], max(unused[i % 2][j] + abs(x[k] - x[j]), t[i]));
          }
        }
        if (unused[i % 2][j] + abs(x[i + 1] - x[j]) <= t[i + 1]) {
          set_min(unused[1 - i % 2][i + 1], t[i + 1]);
        }
      }
    }

    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k < 2; ++k) {
        if (used[i % 2][j][k] != INT_MAX) {
          int u = (k == 0) ? i : j;
          if (j == i + 1) {
            if (used[i % 2][j][k] <= t[i + 1]) {
              set_min(unused[1 - i % 2][u], used[i % 2][j][k]);
            }
          } else {
            if (used[i % 2][j][k] + abs(x[i + 1] - x[u]) <= t[i + 1]) {
              set_min(used[1 - i % 2][j][0], t[i + 1]);
            }
          }
        }
      }
    }
  }

  bool ans = false;
  for (int i = 0; i <= n; ++i) {
    ans |= (unused[n % 2][i] < INT_MAX);
  }

  cout << (ans ? "YES" : "NO") << "\n";
}