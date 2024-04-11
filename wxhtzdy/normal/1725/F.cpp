/**
 *    author:  wxhtzdy
 *    created: 17.09.2022 10:25:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> l(n);
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    --l[i]; --r[i];
  }
  vector<int> ans(31);
  for (int b = 0; b <= 30; b++)  {
    vector<pair<int, int>> ev;
    for (int i = 0; i < n; i++) {
      if (l[i] + (1 << b) - 1 <= r[i]) {
        ev.emplace_back(0, +1);
      } else {
        int L = (l[i] % (1 << b));
        int R = (r[i] % (1 << b));
        if (L <= R) {
          ev.emplace_back(L, +1);
          ev.emplace_back(R + 1, -1);
        } else {
          ev.emplace_back(0, +1);
          ev.emplace_back(R + 1, -1);
          ev.emplace_back(L, +1);  
        }
      }
    }
    sort(ev.begin(), ev.end());
    int bal = 0;
    for (auto& p : ev) {
      bal += p.second;
      ans[b] = max(ans[b], bal);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int w;
    cin >> w;                
    for (int i = 0; i <= 30; i++) {
      if (w >> i & 1) {
        cout << ans[i] << '\n';
        break;
      }
    }
  }                         
  return 0;
}