#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += (x % i == 0 && x / i <= n);
  }

  cout << ans << "\n";
}