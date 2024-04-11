#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n * k);
    for (auto &i : a) {
      cin >> i;
    }
    reverse(a.begin(), a.end());

    n = n / 2 + 1;
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
      ans += a[i * n + n - 1];
    }

    cout << ans << "\n";
  }
}