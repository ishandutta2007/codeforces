#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<long long> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }

  for (int i = 0; i < n; ++i) {
    a[i] *= i + 1;
    a[i] *= n - i;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i] % 998244353 * b[n - 1 - i];
    ans %= 998244353;
  }

  cout << ans << "\n";
}