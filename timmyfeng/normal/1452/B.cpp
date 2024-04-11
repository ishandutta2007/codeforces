#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    long long sum = 0;
    long long maximum = 0;
    for (int i = 0; i < n; ++i) {
      long long a;
      cin >> a;
      sum += a;
      maximum = max(maximum, a);
    }
    cout << max((n - 1 - sum % (n - 1)) % (n - 1), maximum * (n - 1) - sum) << "\n";
  }
}