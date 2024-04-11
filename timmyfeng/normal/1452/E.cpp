#include <bits/stdc++.h>
using namespace std;

const int N = 2000;

array<int, 2> segment[N];
int prefix[N];
int value[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < m; ++i) {
    for (auto &j : segment[i]) {
      cin >> j;
    }
    --segment[i][0];
  }

  sort(segment, segment + m, [](array<int, 2> a, array<int, 2> b) {
    return a[0] + a[1] < b[0] + b[1];
  });

  for (int i = 0; i < m; ++i) {
    auto [l, r] = segment[i];
    for (int j = 0; j < n; ++j) {
      value[j] += max(0, min(j + k, r) - max(j, l));
      prefix[i] = max(prefix[i], value[j]);
    }
  }

  int ans = prefix[m - 1];
  fill(value, value + n, 0);
  for (int i = m - 1; i > 0; --i) {
    auto [l, r] = segment[i];
    for (int j = 0; j < n; ++j) {
      value[j] += max(0, min(j + k, r) - max(j, l));
      ans = max(ans, prefix[i - 1] + value[j]);
    }
  }

  cout << ans << "\n";
}