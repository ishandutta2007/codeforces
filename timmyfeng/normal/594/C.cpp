#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

array<int, 2> by_x[N], by_y[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    by_x[i] = {x1 + x2, i};
    by_y[i] = {y1 + y2, i};
  }

  sort(by_x, by_x + n);
  sort(by_y, by_y + n);

  long long ans = LLONG_MAX;
  for (int a = 0; a <= k; ++a) {
    for (int b = 0; b <= k; ++b) {
      for (int c = 0; c <= k; ++c) {
        for (int d = 0; d <= k; ++d) {
          set<int> magnets;
          for (int i = 0; i < a; ++i) {
            magnets.insert(by_x[i][1]);
          }
          for (int i = n - b; i < n; ++i) {
            magnets.insert(by_x[i][1]);
          }
          for (int i = 0; i < c; ++i) {
            magnets.insert(by_y[i][1]);
          }
          for (int i = n - d; i < n; ++i) {
            magnets.insert(by_y[i][1]);
          }

          if ((int) magnets.size() <= k) {
            int dx = by_x[n - 1 - b][0] - by_x[a][0];
            int dy = by_y[n - 1 - d][0] - by_y[c][0];
            ans = min(ans, (long long) max(1, (dx + 1) / 2) * max(1, (dy + 1) / 2));
          }
        }
      }
    }
  }

  cout << ans << "\n";
}