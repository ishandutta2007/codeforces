#include <bits/stdc++.h>
using namespace std;

const int N = 10'000;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    long long target = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      target += a[i];
    }

    if (target % n != 0) {
      cout << -1 << "\n";
      continue;
    }
    target /= n;

    cout << (n - 1) * 3 << "\n";

    for (int i = 2; i <= n; ++i) {
      int c = (a[i] - 1) / i + 1;
      cout << 1 << " " << i << " " << c * i - a[i] << "\n";
      cout << i << " " << 1 << " " << c << "\n";
    }

    for (int i = 2; i <= n; ++i) {
      cout << 1 << " " << i << " " << target << "\n";
    }
  }
}