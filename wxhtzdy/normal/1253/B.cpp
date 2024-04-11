/**
 *  author: milos
 *  created: 07.01.2021 16:50:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans;
  map<int, int> was;
  int cnt = 0;
  map<int, int> ent;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      if (was[a[i]] == 1 || ent[a[i]] == 1) {
        cout << -1 << '\n';
        return 0;
      }
      was[a[i]]++;
      cnt += 1;
      ent[a[i]] = 1;
    } else {
      if (was[-a[i]] == 0) {
        cout << -1 << '\n';
        return 0;  
      }
      was[-a[i]]--;
      cnt -= 1;
      if (cnt == 0) {
        ans.push_back(i + 1);
        ent.clear();
      }
    }
  }
  for (int i = 0; i <= 1e6; i++) {
    if (was[i] > 0) {
      cout << -1 << '\n';
      return 0;
    }
  }
  cout << ans.size() << '\n';
  cout << ans[0] << " ";
  for (int i = 1; i < (int) ans.size(); i++) {
    cout << ans[i] - ans[i - 1] << " ";
  }
  return 0;
}