#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int M = (1 << 22);
  vector<int> dp(M, -1);
  for (int i = 0; i < n; i++) {
    dp[a[i]] = a[i];
  }
  for (int i = 1; i < M; i++) {
    for (int j = 0; j < 22; j++) {
      if ((i & (1 << j)) && dp[i ^ (1 << j)] > 0) {
        dp[i] = dp[i ^ (1 << j)];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << dp[(M - 1) ^ a[i]];
  }
  return 0;
}