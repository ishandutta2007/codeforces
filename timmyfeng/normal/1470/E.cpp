#include <bits/stdc++.h>
using namespace std;

const int N = 30000 + 1;
const int C = 4 + 1;

long long ways[N][C];

long long before[N][C], after[N][C], y;
int perm[N], n, c, q, x;
vector<int> options[N];

void solve(int i, int j) {
  int l = i, r = n;
  while (l < r) {
    int m = (l + r + 1) / 2;
    long long a = after[m][j] - after[i][j];
    long long b = before[m][j] - before[i][j];
    if (b <= y && y + a < ways[n - i][j]) {
      l = m;
    } else {
      r = m - 1;
    }
  }

  if (l == n) {
    cout << perm[x] << "\n";
    return;
  }

  y -= before[l][j] - before[i][j];
  for (auto k : options[l]) {
    int a = l + k + 1;
    if (k <= j) {
      if (ways[n - a][j - k] <= y) {
        y -= ways[n - a][j - k];
      } else {
        reverse(perm + l, perm + a);
        solve(a, j - k);
        reverse(perm + l, perm + a);
        return;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < C; ++j) {
      if (i == 0) {
        ways[i][j] = 1;
      } else {
        ways[i][j] = (j == 0) ? 0 : ways[i][j - 1];
        long long choose = 1;
        for (int k = 0; k < j; ++k) {
          choose *= i - 1 - k;
          choose /= k + 1;
        }
        ways[i][j] += choose;
      }
    }
  }

  int t;
  cin >> t;

  while (t--) {
    cin >> n >> c >> q;

    for (int i = 0; i < n; ++i) {
      cin >> perm[i];
    }

    for (int i = 0; i < n; ++i) {
      options[i].clear();
      for (int j = 0; j <= c && i + j < n; ++j) {
        options[i].push_back(j);
      }

      sort(options[i].begin(), options[i].end(), [&](int a, int b) {
        return perm[i + a] < perm[i + b];
      });

      for (int j = 0; j <= c; ++j) {
        before[i + 1][j] = after[i + 1][j] = 0;
        for (auto k : options[i]) {
          int a = i + k + 1;
          if (k <= j) {
            if (perm[i + k] < perm[i]) {
              before[i + 1][j] += ways[n - a][j - k];
            } else if (perm[i + k] > perm[i]) {
              after[i + 1][j] += ways[n - a][j - k];
            }
          }
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= c; ++j) {
        before[i + 1][j] += before[i][j];
        after[i + 1][j] += after[i][j];
      }
    }

    while (q--) {
      cin >> x >> y;
      --x, --y;
      if (y >= ways[n][c]) {
        cout << -1 << "\n";
      } else {
        solve(0, c);
      }
    }
  }
}