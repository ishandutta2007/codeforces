#include <bits/stdc++.h>
using namespace std;

const int N = 300;

queue<char> grid[N][N];
string goal[N][N];
int src[N][N][2];

vector<array<int, 4>> ans;

void play(int a, int b, int c, int d) {
  ans.push_back({a, b, c, d});
  grid[c][d].push(grid[a][b].front());
  grid[a][b].pop();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      string s;
      cin >> s;
      reverse(s.begin(), s.end());
      for (auto k : s) {
        grid[i][j].push(k);
      }
    }
  }

  int offset = 0;
  while (!grid[0][0].empty()) {
    if (grid[0][0].front() == '0') {
      play(0, 0, 1, 0);
    } else {
      play(0, 0, 0, 1);
      ++offset;
    }
  }

  while ((int) grid[0][1].size() > offset) {
    if (grid[0][1].front() == '0') {
      play(0, 1, 0, 0);
    } else {
      play(0, 1, 1, 1);
    }
  }

  for (int i = m - 1; i >= 2; --i) {
    for (int j = 0; j < n; ++j) {
      while (!grid[j][i].empty()) {
        play(j, i, j, grid[j][i].front() - '0');
      }
    }
  }

  for (auto i : {1, 0, 1}) {
    for (int j = 1; j < n; ++j) {
      while (!grid[j][i].empty()) {
        if (grid[j][i].front() - '0' == i) {
          play(j, i, 0, i);
        } else {
          play(j, i, j, 1 - i);
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      src[i][j][0] = i;
      src[i][j][1] = i;
      if (j < 2) {
        src[i][j][j] = (i > 0) ? i - 1 : i + 1;
      }

      cin >> goal[i][j];
      reverse(goal[i][j].begin(), goal[i][j].end());
      for (auto k : goal[i][j]) {
        int c = k - '0';
        if (src[i][j][c] != 0) {
          play(0, c, src[i][j][c], c);
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (auto k : goal[i][j]) {
        int c = k - '0';
        play(src[i][j][c], c, i, j);
      }
    }
  }

  cout << ans.size() << "\n";
  for (auto [a, b, c, d] : ans) {
    cout << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << "\n";
  }
}