/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 12:02:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  if (n % 2 == 1) {
    cout << "NO" << '\n';
  } else {
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
      nums.push_back(i);
    }
    vector<pair<int, int>> ans;
    while ((int) nums.size() > 0) {
      int p2 = 1;
      while (p2 * 2 <= nums.back()) {
        p2 *= 2;
      }
      int Q = 0;                 
      for (int i = p2; i <= nums.back(); i++) {
        ans.emplace_back(i, p2 - 1 - (i - p2));
        ans.emplace_back(p2 - 1 - (i - p2), i);
        Q += 2;
      }
      while (Q--) {
        nums.pop_back();
      }
    }
    sort(ans.begin(), ans.end());
    cout << "YES" << '\n';
    for (int i = 0; i < (int) ans.size(); i++) {
      cout << ans[i].second << " ";
    }
    cout << '\n';
  }
  if (n <= 5 || __builtin_popcount(n) == 1) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
    function<void(int)> Gen = [&](int n) {
      vector<int> perm(n);
      iota(perm.begin(), perm.end(), 1);
      do {
        bool ok = true;           
        for (int i = 0; i < n; i++) {
          if ((perm[i] & (i + 1)) == 0 || i + 1 == perm[i]) {
            ok = false;
          }
        }
        if (ok) {
          for (int i = 0; i < n; i++) {
            cout << perm[i] << " ";
          }
          return;
        }
      } while (next_permutation(perm.begin(), perm.end()));
      assert(false);
    };
    if (n <= 6) {
      Gen(n);
      return 0;
    }
    int p2 = 8;
    vector<pair<int, int>> segs;
    segs.emplace_back(1, 7);
    while (p2 <= n) {
      segs.emplace_back(p2, min(p2 * 2 - 1, n));
      p2 *= 2;
    }
    Gen(7);
    for (int i = 1; i < (int) segs.size(); i++) {
      vector<int> p;
      for (int j = segs[i].first; j <= segs[i].second; j++) {
        p.push_back(j);
      }
      int sz = (int) p.size();
      for (int j = 0; j < sz; j++) {
        cout << p[(j + 1) % sz] << " ";
      }
    }
  }
  return 0;
}