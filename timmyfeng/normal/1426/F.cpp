#include <bits/stdc++.h>
using namespace std;

const int M = 1'000'000'007;

int dp[4][4];

int add(int &a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

int pow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  dp[0][0] = 1;

  for (auto c : s) {
    if (c == '?') {
      for (int i = 2; i >= 0; --i) {
        for (int j = 2; j >= 0; --j) {
          add(dp[i + 1][j + 1], dp[i][j]);
        }
      }
    } else {
      int i = c - 'a';
      for (int j = 2; j >= 0; --j) {
        add(dp[i + 1][j], dp[i][j]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= 3; ++i) {
    add(ans, mul(dp[3][i], pow(3, count(s.begin(), s.end(), '?') - i)));
  }

  cout << ans << "\n";
}