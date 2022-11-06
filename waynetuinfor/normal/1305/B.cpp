#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<vector<int>> ans;
  while (true) {
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ')') cnt++;
    }
    int bal = 0, pos = -1;
    vector<int> v;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ')') cnt--;
      if (s[i] == '(') {
        bal++;
        if (bal <= cnt) {
          v.push_back(i); 
          pos = i;
        }
      }
    }
    if (v.empty()) break;
    int k = v.size();
    for (int i = s.size() - 1; k > 0 && i >= 0; --i) {
      if (s[i] == ')') {
        v.push_back(i);
        k--;
      }
    }
    ans.push_back(v);
    vector<bool> used(s.size());
    for (int u : v) used[u] = true;
    string t = "";
    for (int i = 0; i < s.size(); ++i) {
      if (!used[i]) t += s[i];
    }
    s = t;
  }
  cout << ans.size() << "\n";
  for (auto &v : ans) {
    cout << v.size() << "\n";
    sort(v.begin(), v.end());
    for (int u : v) cout << u + 1 << ' ';
    cout << "\n";
  }
}