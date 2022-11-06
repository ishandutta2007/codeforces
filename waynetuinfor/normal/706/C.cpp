#include <string>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

const int maxn = 100000 + 5;
long long dp[2][maxn], c[maxn], ans, n;
string s[2][maxn], str;

const long long INF = LLONG_MAX - 2000000000;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> c[i];
  for (int i = 0; i < n; ++i) {
    cin >> str;
    s[0][i] = str;
    reverse(str.begin(), str.end());
    s[1][i] = str;
  }
  fill(dp[0], dp[0] + n, INF);
  fill(dp[1], dp[1] + n, INF);
  dp[0][0] = 0; dp[1][0] = c[0];
  for (int i = 1; i < n; ++i) {
    if (s[0][i] >= s[1][i - 1]) dp[0][i] = min(dp[0][i], dp[1][i - 1]);
    if (s[0][i] >= s[0][i - 1]) dp[0][i] = min(dp[0][i], dp[0][i - 1]);
    if (s[1][i] >= s[1][i - 1]) dp[1][i] = min(dp[1][i], dp[1][i - 1] + c[i]);
    if (s[1][i] >= s[0][i - 1]) dp[1][i] = min(dp[1][i], dp[0][i - 1] + c[i]);
  }
  if (min(dp[0][n - 1], dp[1][n - 1]) == INF) { cout << "-1\n"; return 0; }
  else ans = min(dp[0][n - 1], dp[1][n - 1]);
  cout << ans << '\n';
}