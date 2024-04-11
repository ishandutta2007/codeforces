#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int add(int x, int y) {
  return (x + y >= mod ? x + y - mod : x + y);
}

int sub(int x, int y) {
  return (x - y < 0 ? x - y + mod : x - y);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, k;
  cin >> t >> k;
  const int N = 1e5 + 5;
  vector<int> dp(N), pref(N);
  dp[0] = 1;
  for (int i = 1; i < N; i++) {
    dp[i] = add(dp[i - 1], (i >= k ? dp[i - k] : 0));
    pref[i] = add(pref[i - 1], dp[i]);
  }
  while (t--) {
    int L, R;
    cin >> L >> R;
    cout << sub(pref[R], pref[L - 1]) << '\n';
  }
  return 0;
}