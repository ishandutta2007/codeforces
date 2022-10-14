/**
 *  author: milos
 *  created: 14.12.2020 13:08:35
**/
#include <bits/stdc++.h>

using namespace std;              

void Do(vector<int>& a, int i) {
  swap(a[i + 1], a[i + 2]);
  swap(a[i], a[i + 1]);  
}

bool Ok(vector<int> a) {
  vector<int> b = a;
  sort(b.begin(), b.end());
  for (int i = 0; i < (int) a.size(); i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

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
    vector<pair<int, int>> all(n);
    for (int i = 0; i < n; i++) {
      all[i] = {a[i], i};
    }
    sort(all.begin(), all.end());
    for (int i = 0; i < n; i++) {
      a[all[i].second] = i;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i] > a[j]) {
          cnt++;
        }
      }
    }
    if (cnt % 2 == 1) {
      for (int i = 0; i < n - 1; i++) {
        if (all[i].first == all[i + 1].first) {
          swap(a[all[i].second], a[all[i + 1].second]);
          break;
        }
      }
    }
    vector<int> ans;
    for (int i = 0; i < n - 2; i++) {
      int j = min_element(a.begin() + i, a.end()) - a.begin();
      while (j > i + 1) {
        Do(a, j - 2);
        ans.push_back(j - 2);
        j -= 2;
      }
      if (j != i) {
        for (int t = 0; t < 2; t++) {
          Do(a, i);
          ans.push_back(i);
        }
        j = i;
      }
    }
    for (int i = 0; i < 3; i++) {
      if (Ok(a)) break;
      Do(a, n - 3);      
      ans.push_back(n - 3);  
    }
    if (!Ok(a)) {
      cout << -1 << '\n';
    } else {
      cout << (int) ans.size() << '\n';
      for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] + 1 << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}