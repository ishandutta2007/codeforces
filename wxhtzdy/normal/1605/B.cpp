#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) {
        ans.push_back(i);
      }
    }
    cout << min((int) ans.size(), 1) << '\n';
    if (!ans.empty()) {
      cout << ans.size() << " ";
      for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] + 1 << " ";
      }
      cout << '\n';
    }
  }
}