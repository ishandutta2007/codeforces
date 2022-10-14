/**
 *    author:  wxhtzdy
 *    created: 16.08.2022 16:37:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> ans;            
    for (int i = 1; i <= n; i += 4) {
      vector<int> p;
      for (int j = i; j <= min(i + 3, n); j++) {
        p.push_back(j);
      }
      do {
        bool ok = true;     
        for (int l = 0; l < (int) p.size(); l += 2) {
          if (((p[l] + k) * 1LL * p[l + 1]) % 4 != 0) {
            ok = false;            
          }
        }
        if (ok) {
          for (int l = 0; l < (int) p.size(); l += 2) {
            ans.emplace_back(p[l], p[l + 1]);
          }
          break;
        }
      } while (next_permutation(p.begin(), p.end()));
    }
    if (ans.size() != n / 2) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << '\n';
      }
    }
  }                                                                    
  return 0;
}