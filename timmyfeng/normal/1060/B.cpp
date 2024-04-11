#include <bits/stdc++.h>
using namespace std;

map<long long, int> memo;

int solve(long long n) {
  if (memo.count(n) == 0) {
    for (int i = 0; i <= 18; ++i) {
      if (i <= n && (n - i) % 10 == 0) {
        memo[n] = max(memo[n], i + solve((n - i) / 10));
      }
    }
  }
  return memo[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;
  memo[0] = 0;
  cout << solve(n) << "\n";
}