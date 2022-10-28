#include <bits/stdc++.h>
using namespace std;

const int N = 50;
const int O = 1e6;

pair<int, int> nxt[4][N];
int grid[4][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<tuple<int, int, int>> ans;
  auto check = [&](int i, int j){
    int ii = (i == 1) ? 0 : 3;
    if (grid[i][j] != 0 && grid[ii][j] == grid[i][j]) {
      ans.emplace_back(grid[i][j], ii, j);
      grid[i][j] = 0;
      --k;
    }
  };

  nxt[1][0] = {2, 0};
  nxt[2][n - 1] = {1, n - 1};
  for (int i = 1; i < n; ++i) {
    nxt[1][i] = {1, i - 1};
    nxt[2][i - 1] = {2, i};
  }

  int i = 2;
  int j = 0;
  int ii = 1;
  int jj = 0;
  for (int z = 0; z < O; ++z) {
    check(i, j);
    if (grid[i][j] != 0 && grid[ii][jj] == 0) {
      ans.emplace_back(grid[i][j], ii, jj);
      swap(grid[i][j], grid[ii][jj]);
    }

    tie(ii, jj) = make_pair(i, j);
    tie(i, j) = nxt[i][j];
  }

  if (k == 0) {
    cout << ans.size() << "\n";
    for (auto [a, b, c] : ans) {
      cout << a << " " << b + 1 << " " << c + 1 << "\n";
    }
  } else {
    cout << -1 << "\n";
  }
}