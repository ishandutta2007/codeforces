#include <bits/stdc++.h>
using namespace std;

const int N = 50 + 1;

array<int, 4> restrictions[N];
int cost[N][N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, h, m;
  cin >> n >> h >> m;

  for (int i = 0; i < m; ++i) {
    for (auto j : {2, 3, 0, 1}) {
      cin >> restrictions[i][j];
    }
    --restrictions[i][2];
  }
  sort(restrictions, restrictions + m);

  for (int len = 1; len <= n; ++len) {
    for (int l = 0; l + len <= n; ++l) {
      int r = l + len;
      fill(cost[l][r], cost[l][r] + h + 1, INT_MIN);

      for (int i = l; i < r; ++i) {
        int ptr = 0;
        int fines = 0;
        for (int j = 0; j <= h; ++j) {
          while (ptr < m && restrictions[ptr][0] < j) {
            auto [x, c, ll, rr] = restrictions[ptr++];
            if (l <= ll && rr <= r && ll <= i && i < rr) {
              fines += c;
            }
          }
          cost[l][r][j] = max(cost[l][r][j], j * j - fines + cost[l][i][j] + cost[i + 1][r][j]);
        }
      }

      for (int i = 1; i <= h; ++i) {
        cost[l][r][i] = max(cost[l][r][i], cost[l][r][i - 1]);
      }
    }
  }

  cout << cost[0][n][h] << "\n";
}