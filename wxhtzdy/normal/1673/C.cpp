#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 4e4 + 5;
  vector<int> dp(N);
  dp[0] = 1;
  for (int i = 1; i < N; i++) {
    vector<int> v;
    int x = i;
    while (x > 0) {
      v.push_back(x % 10);
      x /= 10;
    }
    bool is = true;
    int sz = v.size();
    for (int j = 0; j < sz; j++) {
      is &= (v[j] == v[sz - j - 1]);
    }
    if (is) {
      for (int j = i; j < N; j++) {
       dp[j] = (dp[j] + dp[j - i]) % md;
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
  }
}