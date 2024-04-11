#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  bitset<5000> dp;
  dp[0] = 1;
  for (int i = 0; i < min(n, 50); ++i) {
    dp = (dp << 1) | (dp << 5) | (dp << 10) | (dp << 50);
  }

  if (n <= 50) {
    cout << dp.count() << "\n";
  } else {
    cout << dp.count() + (n - 50) * 49LL << "\n";
  }
}