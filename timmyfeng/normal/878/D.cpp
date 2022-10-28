#include <bits/stdc++.h>
using namespace std;

const int K = 12 + 1;
const int C = 1 << 12;
const int N = 100000 + K;

bitset<C> mask[N];
int a[K][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, q;
  cin >> n >> k >> q;

  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < (1 << k); ++i) {
    for (int j = 0; j < k; ++j) {
      mask[j + 1][i] = ((i & (1 << j)) > 0);
    }
  }

  int cnt = k;
  while (q--) {
    int type, x, y;
    cin >> type >> x >> y;

    if (type == 3) {
      int ans = 0;
      for (int i = 1; i <= k; ++i) {
        int cur = 0;
        for (int j = 0; j < k; ++j) {
          cur |= (a[j + 1][y] >= a[i][y]) << j;
        }
        if (mask[x][cur]) {
          ans = max(ans, a[i][y]);
        }
      }
      cout << ans << "\n";
    } else {
      if (type == 1) {
        mask[++cnt] = mask[x] | mask[y];
      } else {
        mask[++cnt] = mask[x] & mask[y];
      }
    }
  }
}