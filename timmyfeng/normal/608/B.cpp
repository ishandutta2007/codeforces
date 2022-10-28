#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

int ones[N], zeroes[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  cin >> a >> b;
  int n = b.size(), m = a.size();

  for (int i = 0; i < n; ++i) {
    zeroes[i + 1] = zeroes[i] + '1' - b[i];
    ones[i + 1] = ones[i] + b[i] - '0';
  }

  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    if (a[i] == '1') {
      ans += zeroes[n - m + 1 + i] - zeroes[i];
    } else {
      ans += ones[n - m + 1 + i] - ones[i];
    }
  }

  cout << ans << "\n";
}