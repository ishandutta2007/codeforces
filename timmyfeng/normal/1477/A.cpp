#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> x(n);
    for (auto &i : x) {
      cin >> i;
    }
    sort(x.begin(), x.end());

    long long g = 0;
    for (int i = 1; i < n; ++i) {
      g = __gcd(g, x[i] - x[i - 1]);
    }

    cout << ((k - x[0]) % g == 0 ? "YES" : "NO") << "\n";
  }
}