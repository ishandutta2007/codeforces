#include <iostream>
#include <string>
using namespace std;

int n, dp[200005], cnt;
string s;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  cin >> s;
  // if (s[0] == '<') { cout << 1 << endl; return 0; }
  // if (s[n - 1] == '>') { cout << n << endl; return 0; }
  // if (s[0] == '>') { cout << 0 << endl; return 0; }
  // if (s[n - 1] == '<') { cout << 0 << endl; return 0; }
  // for (int i = 0; i < n; ++i) {
  //
  // }
  dp[0] = (s[0] == '<');
  if (dp[0]) cnt++;
  dp[n - 1] = (s[n - 1] == '>');
  if (dp[n - 1]) cnt++;
  for (int i = 1; i < n; ++i) {
    if (!dp[i] && dp[i - 1] && s[i] == '<') dp[i] = 1, cnt++;
  }
  for (int i = n - 2; i >= 0; --i) {
    if (!dp[i] && dp[i + 1] && s[i] == '>') dp[i] = 1, cnt++;
  }
  cout << cnt << endl;
  return 0;
}