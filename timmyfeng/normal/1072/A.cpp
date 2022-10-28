#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int k) {
  if (k == 0)
    return 0;
  return 2 * n + 2 * m - 4 + solve(n - 4, m - 4, k - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  cout << solve(n, m, k) << "\n";
}