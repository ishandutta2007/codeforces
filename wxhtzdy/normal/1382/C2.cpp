#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s += '0', t += '0';
    vector<int> x, y;
    for (int i = 1; i <= n; i++) {
      if (s[i] != s[i - 1]) {
        x.push_back(i);
      }
      if (t[i] != t[i - 1]) {
        y.push_back(i);
      }
    }
    reverse(y.begin(), y.end());
    vector<int> ans;
    for (int i : x) {
      ans.push_back(i);
    }
    for (int i : y) {
      ans.push_back(i);
    }
    cout << (int) ans.size() << " ";
    for (int i : ans) {
      cout << i << " ";
    }
    cout << '\n';
  }
  return 0;
}