#include <bits/stdc++.h>
using namespace std;

const int N = 300000;

long long sum[N], a[3][N];
int n[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (auto &i : n) {
    cin >> i;
  }

  long long total = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n[i]; ++j) {
      cin >> a[i][j];
      total += a[i][j];
      sum[i] += a[i][j];
    }
    sort(a[i], a[i] + n[i]);
  }

  cout << max({
    total - 2 * *min_element(sum, sum + 3),
    total - 2 * (a[0][0] + a[1][0]),
    total - 2 * (a[0][0] + a[2][0]),
    total - 2 * (a[1][0] + a[2][0])
  }) << "\n";
}