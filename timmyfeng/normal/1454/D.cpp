#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long n;
    cin >> n;

    vector<array<long long, 2>> factors;
    for (long long i = 2; i * i <= n; ++i) {
      int count = 0;
      while (n % i == 0) {
        ++count;
        n /= i;
      }
      factors.push_back({count, i});
    }
    if (n > 1) {
      factors.push_back({1, n});
    }
    sort(factors.rbegin(), factors.rend());

    int k = factors[0][0];
    vector<long long> ans(k, 1);
    for (auto [a, b] : factors) {
      for (int i = k - a; i < k; ++i) {
        ans[i] *= b;
      }
    }

    cout << k << "\n";
    for (auto i : ans) {
      cout << i << " ";
    }
    cout << "\n";
  }
}