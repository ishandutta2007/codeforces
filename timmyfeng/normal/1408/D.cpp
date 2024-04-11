#include <bits/stdc++.h>
using namespace std;

const int N = 2'000;
const int M = 1'000'000 + 2;

int searchlight[N][2];
int robber[N][2];
int move_y[M];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> robber[i][j];
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> searchlight[i][j];
    }
  }

  vector<array<int, 2>> move_x;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (robber[i][0] <= searchlight[j][0] && robber[i][1] <= searchlight[j][1]) {
        int diff_x = searchlight[j][0] - robber[i][0] + 1;
        int diff_y = searchlight[j][1] - robber[i][1] + 1;
        move_x.push_back({diff_x, diff_y});
        ++move_y[diff_y];
      }
    }
  }

  sort(move_x.begin(), move_x.end());
  int ptr_y = M - 1;
  while (ptr_y > 0 && move_y[ptr_y] == 0) {
    --ptr_y;
  }
  int ans = ptr_y;

  for (auto [x, y] : move_x) {
    --move_y[y];
    while (ptr_y > 0 && move_y[ptr_y] == 0) {
      --ptr_y;
    }
    ans = min(ans, x + ptr_y);
  }

  cout << ans << "\n";
}