/**
 *    author:  wxhtzdy
 *    created: 17.09.2022 18:51:16
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
  vector<int> b;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      b.push_back(a[i] * j);
    }
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  int k = (int) b.size();
  vector<vector<int>> g(k);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      int v = a[i] * j;
      int idx = (int) (lower_bound(b.begin(), b.end(), v) - b.begin());
      g[idx].push_back(i);
    }
  }
  vector<bool> was(k);
  vector<int> match(n, -1);
  function<bool(int)> Try = [&](int v) {
    if (was[v]) {
      return false;
    }
    was[v] = true;
    for (int u : g[v]) {
      if (match[u] == -1 || Try(match[u])) {
        match[u] = v;
        return true;        
      }
    }
    return false;
  };
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    if (Try(i)) {
      ans += b[i];     
      fill(was.begin(), was.end(), false);
    }
  }
  cout << ans << '\n';                        
  return 0;
}