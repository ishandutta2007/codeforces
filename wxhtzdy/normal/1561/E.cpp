/**
 *    author:  milos
 *    created: 10.09.2021 18:10:07       
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
    function<void(int)> Reverse = [&](int x) {
      for (int i = 0; i <= x; i++) {
        if (i >= x - i) {
          break;
        }
        swap(a[i], a[x - i]);
      }
    };
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == i % 2) {
        ok = false;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> ans;
    for (int foo = 0; foo < n / 2 && !is_sorted(a.begin(), a.end()); foo++) {
      int x, y;
      for (int i = 0; i < n; i++) {
        if (a[i] == n - foo * 2) {
          x = i;
        }
      }
      ans.push_back(x + 1);   
      Reverse(x);
      for (int i = 0; i < n; i++) {
        if (a[i] == n - foo * 2 - 1) {
          y = i;
        }
      }
      ans.push_back(y);
      Reverse(y - 1);
      ans.push_back(y + 2);
      Reverse(y + 1);
      ans.push_back(3);
      Reverse(2);
      ans.push_back(n - 2 * foo);
      Reverse(n - 2 * foo - 1);
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < (int) ans.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}