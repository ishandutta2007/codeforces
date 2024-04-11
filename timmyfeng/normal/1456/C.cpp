#include <bits/stdc++.h>
using namespace std;

const int N = 500000;

long long c[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  ++k;

  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  sort(c, c + n);

  int m = n;
  long long bonus = 0, sum = 0;
  for (int i = n - 1; i >= 0 && c[i] >= 0; --i) {
    --m;
    sum += bonus;
    bonus += c[i];
  }

  for (int i = 0; i < m; ++i) {
    sum += i / k * c[i];
  }
  sum += bonus * ((m + k - 1) / k);

  long long ans = sum;
  for (int i = m - 1; i >= 0; --i) {
    sum -= i / k * c[i];
    sum += ((i + k - 1) / k) * c[i];
    if (i % k != 0) {
      sum += bonus;
    }
    bonus += c[i];
    ans = max(ans, sum);
  }

  cout << ans << "\n";
}