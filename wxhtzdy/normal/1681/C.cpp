/**
 *    author:  wxhtzdy
 *    created: 23.05.2022 16:39:35
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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i] > a[j] && b[i] < b[j]) {
          ok = false;
        }
        if (a[i] < a[j] && b[i] > b[j]) {
          ok = false;
        }
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j > 0 && (a[j - 1] > a[j] || b[j - 1] > b[j])) {
        ans.emplace_back(j - 1, j);
        swap(a[j - 1], a[j]);
        swap(b[j - 1], b[j]);
        j--;
      }
    }
    cout << ans.size() << '\n';                                    
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
    }
  }                                                                    
  return 0;
}