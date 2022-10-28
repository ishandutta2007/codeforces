#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
const int L = __lg(N) + 1;

array<long long, 2> maxi[L][N];

long long solve(int l, int r) {
  if (l == r) {
    return 0;
  }

  int log = __lg(r - l);
  auto [x, m] = max(maxi[log][l], maxi[log][r - (1 << log)]);

  return solve(l, m) + x * (m - l + 1) * (r - m) + solve(m + 1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 0, a = 0, b; i < n; ++i) {
    cin >> b;
    maxi[0][i] = {abs(b - a), i};
    a = b;
  }

  for (int i = 1; i <= __lg(n); ++i) {
    for (int j = 0; j + (1 << i) <= n; ++j) {
      maxi[i][j] = max(maxi[i - 1][j], maxi[i - 1][j + (1 << (i - 1))]);
    }
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << solve(l, r) << "\n";
  }
}