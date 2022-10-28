#include <bits/stdc++.h>
using namespace std;

const int MOD = (119 << 23) + 1;
const int N = 1e5 + 1;
const int A = 201;

int add(int a ,int b) {
  return (a += b) < MOD ? a : a - MOD;
}

int dp[2][A][2];
int pre[A];
int suf[A];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    int ii = i & 1;
    for (int j = 1; j < A; ++j) {
      if (a[i] == -1 || a[i] == j) {
        if (i == 0) {
          dp[ii][j][1] = 1;
        } else {
          dp[ii][j][0] = add(suf[j], dp[ii ^ 1][j][1]);
          dp[ii][j][1] = pre[j - 1];
        }
      } else {
        dp[ii][j][0] = 0;
        dp[ii][j][1] = 0;
      }
    }

    suf[A - 1] = dp[ii][A - 1][0];
    for (int j = A - 2; j > 0; --j) {
      suf[j] = add(suf[j + 1], dp[ii][j][0]);
    }
    for (int j = 1; j < A; ++j) {
      pre[j] = add(pre[j - 1], add(dp[ii][j][0], dp[ii][j][1]));
    }
  }

  int ans = 0;
  for (int i = 1; i < A; ++i) {
    ans = add(ans, dp[(n - 1) & 1][i][0]);
  }
  cout << ans << "\n";
}