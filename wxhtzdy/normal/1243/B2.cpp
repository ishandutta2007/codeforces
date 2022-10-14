/**
 *    author:  milos
 *    created: 28.01.2021 02:14:39       
**/
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
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
      cnt[(int) (s[i] - 'a')]++;
      cnt[(int) (t[i] - 'a')]++;
    }
    bool ok = true;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % 2 == 1) {
        ok = false;  
      }
    }
    if (!ok) {
      cout << "No" << '\n';
      continue;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
      if (s[i] == t[i]) {
        continue;
      }
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j]) {
          ans.emplace_back(j, i);
          swap(t[i], s[j]);
          break;
        }
        if (s[i] == t[j]) {
          ans.emplace_back(j, j);
          ans.emplace_back(j, i);
          swap(s[j], t[j]);
          swap(t[i], s[j]);
          break;
        }
      }
    }  
    cout << "Yes" << '\n';
    cout << (int) ans.size() << '\n';
    for (auto c : ans) {
      cout << c.first + 1 << " " << c.second + 1 << '\n';
    }
  }
  return 0;
}