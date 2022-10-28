#include <bits/stdc++.h>
using namespace std;

vector<array<int, 2>> ans;
int n, m;

void transpose(vector<string>& grid) {
  vector<string> res(m, string(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      switch (grid[i][j]) {
        case 'L':
          res[j][i] = 'U';
          break;
        case 'R':
          res[j][i] = 'D';
          break;
        case 'U':
          res[j][i] = 'L';
          break;
        default:
          res[j][i] = 'R';
      }
    }
  }
  swap(n, m);
  grid = res;
}

void rotate(vector<string> &grid, int r, int c) {
  ans.push_back({r, c});
  if (grid[r][c] == 'L') {
    grid[r][c] = 'U';
    grid[r][c + 1] = 'U';
    grid[r + 1][c] = 'D';
    grid[r + 1][c + 1] = 'D';
  } else {
    grid[r][c] = 'L';
    grid[r][c + 1] = 'R';
    grid[r + 1][c] = 'L';
    grid[r + 1][c + 1] = 'R';
  }
}

void flatten(vector<string> &grid, int r, int cl, int cr) {
  if (cl == cr) {
    return;
  }
  assert(r < n);

  int i = cl;
  while (i < cr) {
    while (i < cr && grid[r][i] == 'U') {
      ++i;
    }

    int j = i;
    while (i < cr && grid[r][i] == 'L') {
      i += 2;
    }

    if (j % 2 != cl % 2) {
      flatten(grid, r + 1, j, i);
    }
  }

  for (int i = cl; i < cr; ++i) {
    if (grid[r][i] == 'L' && i % 2 != cl % 2) {
      rotate(grid, r, i);
    }
  }

  for (int i = cl; i < cr; ++i) {
    if (grid[r][i] == 'U') {
      rotate(grid, r, i);
    }
  }
}

void solve(vector<string> grid) {
  bool flip = false;
  if (grid.size() % 2 != 0) {
    transpose(grid);
    flip = true;
  }

  ans.clear();

  for (int i = 0; i < n; i += 2) {
    int j = 0;
    while (j < m) {
      while (j < m && grid[i][j] == 'U') {
        ++j;
      }

      int k = j;
      while (j < m && grid[i][j] == 'L') {
        j += 2;
      }
      flatten(grid, i + 1, k, j);
    }

    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'L') {
        rotate(grid, i, j);
      }
    }
  }

  if (flip) {
    swap(n, m);
    for (auto &[a, b] : ans) {
      swap(a, b);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  vector<string> start(n);
  for (auto &i : start) {
    cin >> i;
  }

  vector<string> end(n);
  for (auto &i : end) {
    cin >> i;
  }

  solve(start);
  vector<array<int, 2>> ans_s = ans;
  solve(end);
  vector<array<int, 2>> ans_e = ans;

  while (!ans_e.empty()) {
    ans_s.push_back(ans_e.back());
    ans_e.pop_back();
  }

  cout << ans_s.size() << "\n";
  for (auto [a, b] : ans_s) {
    cout << a + 1 << " " << b + 1 << "\n";
  }
}