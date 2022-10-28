#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
const int K = 2000 + 1;

int a[N], sum[K], offer[K], cost[K];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  reverse(a, a + k);

  for (int i = 0; i < k; ++i) {
    sum[i + 1] = a[i] + sum[i];
  }

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    if (x <= k) {
      offer[x] = max(offer[x], y);
    }
  }

  for (int i = 1; i <= k; ++i) {
    cost[i] = INT_MAX;
    for (int j = 1; j <= i; ++j) {
      cost[i] = min(cost[i], cost[i - j] + (sum[i] - sum[i - j]) - (sum[i] - sum[i - offer[j]]));
    }
  }

  cout << cost[k] << "\n";
}