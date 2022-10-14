/**
 *    author:  milos
 *    created: 25.03.2021 16:26:51       
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
    auto Min = [&](vector<int> a) {
      vector<int> ans(n);
      vector<bool> was(n + 1, false);
      for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
          was[a[i]] = true;
          ans[i] = a[i];
        }
      }
      vector<int> left;
      for (int i = 1; i <= n; i++) {
        if (!was[i]) {
          left.push_back(i);
        }
      }
      int j = 0;
      for (int i = 0; i < n; i++) {
        if (ans[i] == 0) {
          ans[i] = left[j++];
        }
      }
      return ans;
    };
    auto Max = [&](vector<int> a) {
      vector<int> ans(n);
      vector<bool> was(n + 1, false);
      for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
          was[a[i]] = true;
          ans[i] = a[i]; 
        }
      }
      set<int> s;
      for (int i = 1; i <= n; i++) {
        if (!was[i]) {
          s.insert(i);
        }
      }
      for (int i = 0; i < n; i++) {
        if (ans[i] != 0) {
          continue;
        }
        auto it = s.lower_bound(a[i] + 1);
        assert(it != s.begin());
        it--;
        ans[i] = *it;
        s.erase(it);
      }
      return ans;
    };
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans = Min(a);
    for (int i : ans) cout << i << " ";
    cout << '\n';
    ans = Max(a);
    for (int i : ans) cout << i << " ";
    cout << '\n';
  }
  return 0;
}