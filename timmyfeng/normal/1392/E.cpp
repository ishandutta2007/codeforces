#include <bits/stdc++.h>
using namespace std;

const int N = 25;

long long grid[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      grid[i][j] = (1LL * i % 2) << (i + j);
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }

  int q;
  cin >> q;
  while (q--) {
    long long a;
    int x = 0;
    int y = 0;
    cin >> a;

    while (x != n - 1 || y != n - 1) {
      cout << x + 1 << " " << y + 1 << endl;
      bool on = ((a & (1LL << (x + y + 1))) > 0);
      for (int i = 0; i < 2; ++i) {
        int x_new = x + i;
        int y_new = y + 1 - i;
        if (x_new < n && y_new < n && (on ^ (grid[x_new][y_new] == 0))) {
          x = x_new;
          y = y_new;
          break;
        }
      }
    }
    cout << n << " " << n << endl;
  }
}