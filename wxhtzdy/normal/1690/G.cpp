/**
 *    author:  wxhtzdy
 *    created: 07.06.2022 18:39:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }           
    const int inf = (int) 1e9 + 5;
    vector<int> fenw(n + 1, inf);
    function<void(int, int)> update = [&](int i, int v) {
      for (i += 1; i <= n; i += i & -i) {
        fenw[i] = min(fenw[i], v);
      }
    };
    for (int i = 0; i < n; i++) {
      update(i, a[i]);
    }
    auto get = [&](int i) {
      int res = inf;
      for (i += 1; i >= 1; i -= i & -i) {
        res = min(res, fenw[i]);
      }
      return res;
    };
    auto isGood = [&](int i) {
      return get(i) != get(i - 1);  
    };
    set<int> ids;
    for (int i = 0; i < n; i++) {
      if (isGood(i)) {
        ids.insert(i);
      }
    }
    while (m--) {
      int i, v;
      cin >> i >> v;
      --i;         
      a[i] -= v;
      update(i, a[i]);
      if (isGood(i)) {
        ids.insert(i);
      }    
      while (true) {
        auto it = ids.lower_bound(i + 1);
        if (it == ids.end()) {
          break;
        }
        int j = *it;
        if (!isGood(j)) {
          ids.erase(it);
        } else {
          break;
        }
      }
      cout << ids.size() << " ";
    }
    cout << '\n';
  }                                                                   
  return 0;
}