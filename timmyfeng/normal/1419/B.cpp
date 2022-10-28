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

    int ans = 0;
    long long x = 1;
    while (x * (x + 1) / 2 <= n) {
      n -= x * (x + 1) / 2;
      ++ans;
      x = 2 * x + 1;
    }

    cout << ans << "\n";
  }
}