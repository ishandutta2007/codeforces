#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, x;
  cin >> n >> k >> x;

  long long p = 1;
  for (int i = 0; i < k; ++i) {
    p *= x;
  }

  vector<long long> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  vector<long long> prefix(n + 1), suffix(n + 1);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] | a[i];
  }
  for (int i = n - 1; i >= 0; --i) {
    suffix[i] = suffix[i + 1] | a[i];
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, (p * a[i]) | prefix[i] | suffix[i + 1]);
  }

  cout << ans << "\n";
}