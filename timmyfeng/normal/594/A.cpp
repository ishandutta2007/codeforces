#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());

  int ans = a[n - 1] - a[0];
  for (int i = 0; i < n / 2; ++i) {
    ans = min(ans, a[i + n / 2] - a[i]);
  }

  cout << ans << "\n";
}