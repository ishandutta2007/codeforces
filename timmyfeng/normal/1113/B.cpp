#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int sum = 0;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
    sum += i;
  }
  sort(a.begin(), a.end());

  int ans = sum;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= a[i]; ++j) {
      if (a[i] % j == 0) {
        int k = (i == 0) ? 1 : 0;
        ans = min(ans, sum - a[i] - a[k] + a[i] / j + a[k] * j);
      }
    }
  }
  cout << ans << "\n";
}