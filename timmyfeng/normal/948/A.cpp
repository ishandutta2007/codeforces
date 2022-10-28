#include <bits/stdc++.h>
using namespace std;

const int R[] = {0, -1, 0, 1};
const int C[] = {1, 0, -1, 0};
const int N = 500;

string grid[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'W') {
        for (int k = 0; k < 4; ++k) {
          int i_new = i + R[k];
          int j_new = j + C[k];
          if (i_new >= 0 && i_new < n && j_new >= 0 && j_new < m) {
            if (grid[i_new][j_new] == 'S') {
              cout << "No\n";
              exit(0);
            }
          }
        }
      } else if (grid[i][j] == '.') {
        grid[i][j] = 'D';
      }
    }
  }

  cout << "Yes\n";
  for (int i = 0; i < n; ++i) {
    cout << grid[i] << "\n";
  }
}