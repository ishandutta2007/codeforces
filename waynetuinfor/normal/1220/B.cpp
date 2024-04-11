#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> a[i][j];
  }
  int64_t pd = 1LL * a[0][1] * a[1][2] / a[0][2];
  int64_t a1 = sqrt(pd);
  while (a1 * a1 < pd) a1++;
  while ((a1 - 1) * (a1 - 1) >= pd) a1--;
  assert(a1 * a1 == pd);
  for (int i = 0; i < n; ++i) {
    if (i == 1) cout << a1 << ' ';
    else cout << a[i][1] / a1 << ' ';
  }
  cout << "\n";
}