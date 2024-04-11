#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }

  vector<int> b(m);
  for (auto& i : b) {
    cin >> i;
  }

  vector<bool> dp(1 << 9);
  dp[0] = true;

  for (int i = 0; i < n; ++i) {
    vector<bool> dp_new(1 << 9);
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < (1 << 9); ++k) {
        if (dp[k]) {
          dp_new[k | (a[i] & b[j])] = true;
        }
      }
    }
    dp = dp_new;
  }

  int ans = 0;
  while (!dp[ans]) {
    ++ans;
  }

  cout << ans << "\n";
}