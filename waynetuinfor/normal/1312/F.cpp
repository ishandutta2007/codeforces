#include <bits/stdc++.h>
using namespace std;

pair<int, int> per[10][10][10];

void Build() {
  per[1][1][1] = make_pair(2, 0);
  per[1][1][2] = make_pair(3, 0);
  per[1][1][3] = make_pair(4, 0);
  per[1][1][4] = make_pair(5, 0);
  per[1][1][5] = make_pair(6, 0);
  per[1][2][1] = make_pair(3, 0);
  per[1][2][2] = make_pair(3, 0);
  per[1][2][3] = make_pair(4, 8);
  per[1][2][4] = make_pair(5, 10);
  per[1][2][5] = make_pair(6, 0);
  per[1][3][1] = make_pair(4, 0);
  per[1][3][2] = make_pair(4, 8);
  per[1][3][3] = make_pair(2, 3);
  per[1][3][4] = make_pair(7, 12);
  per[1][3][5] = make_pair(2, 11);
  per[1][4][1] = make_pair(5, 0);
  per[1][4][2] = make_pair(5, 10);
  per[1][4][3] = make_pair(7, 12);
  per[1][4][4] = make_pair(5, 3);
  per[1][4][5] = make_pair(3, 26);
  per[1][5][1] = make_pair(6, 0);
  per[1][5][2] = make_pair(6, 0);
  per[1][5][3] = make_pair(2, 11);
  per[1][5][4] = make_pair(3, 26);
  per[1][5][5] = make_pair(2, 5);
  per[2][1][1] = make_pair(3, 0);
  per[2][1][2] = make_pair(3, 5);
  per[2][1][3] = make_pair(4, 8);
  per[2][1][4] = make_pair(5, 7);
  per[2][1][5] = make_pair(6, 11);
  per[2][2][1] = make_pair(3, 5);
  per[2][2][2] = make_pair(4, 0);
  per[2][2][3] = make_pair(5, 0);
  per[2][2][4] = make_pair(6, 0);
  per[2][2][5] = make_pair(7, 0);
  per[2][3][1] = make_pair(4, 8);
  per[2][3][2] = make_pair(5, 0);
  per[2][3][3] = make_pair(5, 0);
  per[2][3][4] = make_pair(6, 0);
  per[2][3][5] = make_pair(7, 12);
  per[2][4][1] = make_pair(5, 7);
  per[2][4][2] = make_pair(6, 0);
  per[2][4][3] = make_pair(6, 0);
  per[2][4][4] = make_pair(6, 0);
  per[2][4][5] = make_pair(7, 20);
  per[2][5][1] = make_pair(6, 11);
  per[2][5][2] = make_pair(7, 0);
  per[2][5][3] = make_pair(7, 12);
  per[2][5][4] = make_pair(7, 20);
  per[2][5][5] = make_pair(7, 4);
  per[3][1][1] = make_pair(2, 3);
  per[3][1][2] = make_pair(4, 8);
  per[3][1][3] = make_pair(4, 10);
  per[3][1][4] = make_pair(5, 13);
  per[3][1][5] = make_pair(6, 9);
  per[3][2][1] = make_pair(4, 8);
  per[3][2][2] = make_pair(5, 0);
  per[3][2][3] = make_pair(5, 7);
  per[3][2][4] = make_pair(6, 11);
  per[3][2][5] = make_pair(7, 12);
  per[3][3][1] = make_pair(4, 10);
  per[3][3][2] = make_pair(5, 7);
  per[3][3][3] = make_pair(6, 0);
  per[3][3][4] = make_pair(7, 0);
  per[3][3][5] = make_pair(8, 0);
  per[3][4][1] = make_pair(5, 13);
  per[3][4][2] = make_pair(6, 11);
  per[3][4][3] = make_pair(7, 0);
  per[3][4][4] = make_pair(7, 0);
  per[3][4][5] = make_pair(8, 0);
  per[3][5][1] = make_pair(6, 9);
  per[3][5][2] = make_pair(7, 12);
  per[3][5][3] = make_pair(8, 0);
  per[3][5][4] = make_pair(8, 0);
  per[3][5][5] = make_pair(8, 0);
  per[4][1][1] = make_pair(5, 3);
  per[4][1][2] = make_pair(3, 14);
  per[4][1][3] = make_pair(5, 15);
  per[4][1][4] = make_pair(5, 17);
  per[4][1][5] = make_pair(6, 22);
  per[4][2][1] = make_pair(3, 14);
  per[4][2][2] = make_pair(6, 0);
  per[4][2][3] = make_pair(6, 11);
  per[4][2][4] = make_pair(6, 9);
  per[4][2][5] = make_pair(7, 17);
  per[4][3][1] = make_pair(5, 15);
  per[4][3][2] = make_pair(6, 11);
  per[4][3][3] = make_pair(7, 0);
  per[4][3][4] = make_pair(7, 9);
  per[4][3][5] = make_pair(8, 14);
  per[4][4][1] = make_pair(5, 17);
  per[4][4][2] = make_pair(6, 9);
  per[4][4][3] = make_pair(7, 9);
  per[4][4][4] = make_pair(8, 0);
  per[4][4][5] = make_pair(9, 0);
  per[4][5][1] = make_pair(6, 22);
  per[4][5][2] = make_pair(7, 17);
  per[4][5][3] = make_pair(8, 14);
  per[4][5][4] = make_pair(9, 0);
  per[4][5][5] = make_pair(9, 0);
  per[5][1][1] = make_pair(2, 5);
  per[5][1][2] = make_pair(3, 11);
  per[5][1][3] = make_pair(2, 12);
  per[5][1][4] = make_pair(6, 18);
  per[5][1][5] = make_pair(6, 26);
  per[5][2][1] = make_pair(3, 11);
  per[5][2][2] = make_pair(7, 4);
  per[5][2][3] = make_pair(7, 12);
  per[5][2][4] = make_pair(7, 13);
  per[5][2][5] = make_pair(7, 16);
  per[5][3][1] = make_pair(2, 12);
  per[5][3][2] = make_pair(7, 12);
  per[5][3][3] = make_pair(8, 0);
  per[5][3][4] = make_pair(8, 14);
  per[5][3][5] = make_pair(8, 11);
  per[5][4][1] = make_pair(6, 18);
  per[5][4][2] = make_pair(7, 13);
  per[5][4][3] = make_pair(8, 14);
  per[5][4][4] = make_pair(9, 0);
  per[5][4][5] = make_pair(9, 11);
  per[5][5][1] = make_pair(6, 26);
  per[5][5][2] = make_pair(7, 16);
  per[5][5][3] = make_pair(8, 11);
  per[5][5][4] = make_pair(9, 11);
  per[5][5][5] = make_pair(10, 0);
}

void Solve() {
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  constexpr int kN = 500;
  vector<vector<int>> dp(kN + 1, vector<int>(3));
  vector<bool> used(10);
  for (int i = 1; i <= kN; ++i) {
    for (int j = 0; j < 3; ++j) {
      vector<int> sg = {dp[max(0, i - x)][0]};
      if (j != 1) sg.push_back(dp[max(0, i - y)][1]);
      if (j != 2) sg.push_back(dp[max(0, i - z)][2]);
      for (int u : sg) used[u] = true;
      while (used[dp[i][j]]) dp[i][j]++;
      for (int u : sg) used[u] = false;
    }
  }
  vector<int64_t> a(n);
  int sum = 0;

  auto Calc = [&](int64_t i, int j) {
    if (i < per[x][y][z].second) return dp[i][j];
    int dist = (i - per[x][y][z].second) % per[x][y][z].first;
    assert(dp[per[x][y][z].second + dist][j] == dp[per[x][y][z].second + dist + per[x][y][z].first][j]);
    return dp[per[x][y][z].second + dist][j];
  };

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum ^= Calc(a[i], 0);
  }
  if (sum == 0) {
    cout << "0\n";
    return;
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    sum ^= Calc(a[i], 0);
    for (int u : {Calc(max(a[i] - x, 0LL), 0), Calc(max(a[i] - y, 0LL), 1), Calc(max(a[i] - z, 0LL), 2)}) {
      if (u == sum) ++res;
    }
    sum ^= Calc(a[i], 0);
  }
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  Build();
  int t;
  cin >> t;
  while (t--) Solve();
}