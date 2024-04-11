#include <bits/stdc++.h>

using namespace std;

const int md = 1e6 + 3;

long long power(long long x, long long y) {
  long long res = 1LL;
  while (y > 0) {
    if (y % 2 != 0) {
      res *= x;
      if (res >= md) {
        res %= md;
      }
    }
    x *= x;
    if (x >= md) {
      x %= md;
    }
    y /= 2;
    //cout << res << endl;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  string ans = "";
  for (int i = 0; i < n; i++) {
    if (s[i] == '>') ans += "1000";
    if (s[i] == '<') ans += "1001";
    if (s[i] == '+') ans += "1010";
    if (s[i] == '-') ans += "1011";
    if (s[i] == '.') ans += "1100";
    if (s[i] == ',') ans += "1101";
    if (s[i] == '[') ans += "1110";
    if (s[i] == ']') ans += "1111";
  }
  long long res = 0;
  for (int i = 0; i < 4 * n; i++) {
    if (ans[i] == '1') {
      int pw = 4 * n - i - 1;
      res += power(2, pw);
      if (res >= md) {
        res %= md;
      }
    }
  }
  cout << res << '\n';
  return 0;
}