#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<long long> a(2 * n);
  for (auto& i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  long long ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
  for (int i = 1; i + n < 2 * n; ++i) {
    ans = min(ans, (a[2 * n - 1] - a[0]) * (a[i + n - 1] - a[i]));
  }
  cout << ans << "\n";
}