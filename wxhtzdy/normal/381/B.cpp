/**
 *    author:  wxhtzdy
 *    created: 08.07.2022 10:10:24
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
  const int MAX = 5005;
  vector<int> cnt(MAX);
  for (int i = 0; i < n; i++) {
    cnt[a[i]] += 1;
  }
  vector<int> ans;
  for (int i = 1; i < MAX; i++) {
    if (cnt[i] > 0) {
      ans.push_back(i);
      cnt[i] -= 1;  
    }
  }
  for (int i = ans.back() - 1; i >= 1; i--) {
    if (cnt[i] > 0) {
      ans.push_back(i);
      cnt[i] -= 1;
    }
  }
  cout << (int) ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}