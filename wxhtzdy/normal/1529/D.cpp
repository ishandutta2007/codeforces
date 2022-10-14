#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

int add(int x, int y) {
  x += y;
  return (x >= md ? x - md : x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      dp[j] += 1;
    }
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = add(dp[i], sum);
    sum = add(sum, dp[i]);
  }
  cout << dp[n] << '\n';
  return 0;
}