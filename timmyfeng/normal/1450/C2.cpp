#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto &i : grid) {
      cin >> i;
    }

    int k = 0;
    vector<int> x(3), o(3);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != '.') {
          ++k;
          if (grid[i][j] == 'X') {
            ++x[(i + j) % 3];
          } else {
            ++o[(i + j) % 3];
          }
        }
      }
    }

    int a = -1, b = -1;
    for (int i = 0; i < 3 && a == -1; ++i) {
      for (int j = 0; j < 3 && a == -1; ++j) {
        if (i != j && x[i] + o[j] <= k / 3) {
          a = i, b = j;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != '.') {
          if ((i + j) % 3 == a) {
            grid[i][j] = 'O';
          } else if ((i + j) % 3 == b) {
            grid[i][j] = 'X';
          }
        }
      }
      cout << grid[i] << "\n";
    }
  }
}