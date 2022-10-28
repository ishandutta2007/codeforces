#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

long long g[N];
int car[N][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, s, t;
  cin >> n >> k >> s >> t;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> car[i][j];
    }
  }

  for (int i = 0; i < k; ++i) {
    cin >> g[i];
  }
  sort(g, g + k);

  g[k] = s - g[k - 1];
  for (int i = k - 1; i > 0; --i) {
    g[i] -= g[i - 1];
  }

  int lo = *max_element(g, g + k + 1);
  int hi = INT_MAX;

  while (lo < hi) {
    int v = lo + (hi - lo) / 2;
    long long need = 0;

    for (int i = 0; i <= k; ++i) {
      need += max(g[i], 3 * g[i] - v);
    }

    if (need <= t) {
      hi = v;
    } else {
      lo = v + 1;
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    if (car[i][1] >= lo) {
      ans = min(ans, car[i][0]);
    }
  }

  cout << (ans == INT_MAX ? -1 : ans) << "\n";
}