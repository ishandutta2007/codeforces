#include <bits/stdc++.h>
using namespace std;

const int N = 100;

set<vector<int>> ans;
string grid[N];

void play(int r, int c, int rs, int cs) {
  vector<int> move;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (r + i != rs || c + j != cs) {
        grid[r + i][c + j] = '0' + '1' - grid[r + i][c + j];
        move.push_back(r + i);
        move.push_back(c + j);
      }
    }
  }

  if (ans.count(move) != 0) {
    ans.erase(move);
  } else {
    ans.insert(move);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> grid[i];
    }
    ans.clear();

    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '1') {
          if (j == m - 1) {
            play(i, j - 1, i, j - 1);
          } else {
            play(i, j, i, j + 1);
          }
        }
      }
    }

    for (int i = 0; i < m; i += 2) {
      if (i == m - 1) {
        --i;
      }

      string pattern = grid[n - 1].substr(i, 2);
      if (pattern != "00") {
        if (pattern != "10") {
          play(n - 2, i, n - 1, i);
        }
        if (pattern != "01") {
          play(n - 2, i, n - 1, i + 1);
        }
        if (pattern != "11") {
          play(n - 2, i, n - 2, i);
          play(n - 2, i, n - 2, i + 1);
        }
      }
    }

    cout << ans.size() << "\n";
    for (auto i : ans) {
      for (auto j : i) {
        cout << j + 1 << " ";
      }
      cout << "\n";
    }
  }
}