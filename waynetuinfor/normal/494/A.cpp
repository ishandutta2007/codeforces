#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int bal = 0;
  vector<int> b(s.size());
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(') bal++;
    if (s[i] == ')' || s[i] == '#') bal--;
    if (bal < 0) {
      cout << "-1\n";
      return 0;
    }
    b[i] = bal;
  }
  vector<int> ans;
  vector<int> a(s.size());
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(') a[i] = 1;
    else a[i] = -1;
  }
  int kv = 0;
  vector<int> p(s.size());
  for (int i = s.size() - 1; i >= 0; --i) {
    kv = min({0, a[i], kv + a[i]});
    p[i] = kv;
  }
  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(') {
      cnt++;
    } else if (s[i] == ')') {
      cnt--;
    } else {
      int r = i + 1 < s.size() ? p[i + 1] : 0;
      int k = min(cnt + r - 1, bal) + 1;
      if (k == 0) {
        cout << "-1\n";
        return 0;
      }
      ans.push_back(k);
      cnt -= k;
      bal -= k - 1;
    }
  }
  if (bal != 0) {
    cout << "-1\n";
    return 0;
  }
  for (int u : ans) {
    cout << u << "\n";
  }
}