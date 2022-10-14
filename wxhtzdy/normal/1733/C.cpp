/**
 *    author:  wxhtzdy
 *    created: 19.09.2022 17:46:04
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (is_sorted(a.begin(), a.end())) {
      cout << 0 << '\n';
      continue;
    }
    vector<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
      int ptr = i;
      while (ptr + 1 < n && (a[ptr + 1] % 2 == a[i] % 2)) {
        ptr += 1;
      }
      s.emplace_back(i, ptr);
      i = ptr;
    }
    vector<pair<int, int>> ops;    
     auto Do = [&](int l, int r) {
      for (int i = r - 1; i >= l; i--) {
        ops.emplace_back(i, i + 1);
      }
    };
    if ((int) s.size() == 1) {
      Do(0, n - 1);
      cout << ops.size() << '\n';
      for (auto& p : ops) {
        cout << p.first + 1 << " " << p.second + 1 << '\n';
      }
      continue;        
    }
    if ((int) s.size() % 2 == 1) {
      for (int i = 0; i < n - 1; i++) {
        if (a[i] % 2 == a[n - 1] % 2) {
          ops.emplace_back(i, n - 1);
        }
      }
      for (int i = 1; i < (int) s.size() - 1; i += 2) {
        for (int j = s[i].first; j <= s[i].second; j++) {
          ops.emplace_back(s[i].first - 1, j);
        }
      } 
      cout << ops.size() << '\n';
      for (auto& p : ops) {
        cout << p.first + 1 << " " << p.second + 1 << '\n';
      }
      continue;        
    }                  
    assert((int) s.size() % 2 == 0);
    for (int i = 1; i < (int) s.size(); i += 2) {
      for (int j = s[i].first; j <= s[i].second; j++) {
        ops.emplace_back(s[0].second, j);
      }
    }
    Do(s[0].first, s[0].second);
    for (int i = 2; i < (int) s.size(); i += 2) {
      ops.emplace_back(s[i].second, s[i + 1].first);
      Do(s[i].first, s[i].second);
    }
    cout << ops.size() << '\n';
    for (auto& p : ops) {
      cout << p.first + 1 << " " << p.second + 1 << '\n';
    }
  }                                                                  
  return 0;
}