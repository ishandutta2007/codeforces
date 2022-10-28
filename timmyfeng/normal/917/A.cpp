#include <bits/stdc++.h>
using namespace std;

int n;

vector<vector<int>> process(string s) {
  vector<vector<int>> res(n, vector<int>(n, n + 1));
  for (int i = 0; i < n; ++i) {
    int bal = 0;
    int cnt = 0;
    int cur = 0;
    for (int j = i; j < n; ++j) {
      if (s[j] == '?') {
        ++cnt;
      } else {
        bal += (s[j] == '(') ? 1 : -1;
      }
      if (bal < 0) {
        if (cnt == 0) {
          break;
        }
        ++cur;
        ++bal;
        --cnt;
      }
      res[i][j] = cur;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  n = s.size();

  vector<vector<int>> pre = process(s);
  for (auto& c : s) {
    if (c != '?') {
      c ^= 1;
    }
  }
  reverse(s.begin(), s.end());
  vector<vector<int>> suf = process(s);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = i; j < n; ++j) {
      cnt += (s[j] == '?');
      ans += (suf[i][j] + pre[n - 1 - j][n - 1 - i] <= cnt && (j - i + 1) % 2 == 0);
    }
  }
  cout << ans << "\n";
}