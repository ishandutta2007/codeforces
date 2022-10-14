#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

int add(int x, int y) {
  x += y;
  return x >= md ? x - md : x;
}

int sub(int x, int y) {
  x -= y;
  return x < 0 ? x + md : x;
}

int mul(int x, int y) {
  return (x * 1LL * y) % md;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n, vector<int>(k + 1, 1));
  for (int j = 1; j <= k; j++) {
    for (int i = 0; i < n; i++) {
      if (i == 0) dp[i][j] = dp[i + 1][j - 1];
      else {
        if (i == n - 1) dp[i][j] = dp[i - 1][j - 1];
        else dp[i][j] = add(dp[i - 1][j - 1], dp[i + 1][j - 1]);
      }
    }
  }
  vector<vector<int>> f(n, vector<int>(k + 1));
  vector<int> S(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      f[i][j] = mul(dp[i][j], dp[i][k - j]);
      S[i] = add(S[i], f[i][j]);
    }
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum = add(sum, mul(a[i], S[i]));
  }
  while (q--) {
    int i, x;
    cin >> i >> x;
    --i;
    sum = sub(sum, mul(a[i], S[i]));
    a[i] = x;
    sum = add(sum, mul(a[i], S[i]));
    cout << sum << '\n';
  }
  return 0;
}