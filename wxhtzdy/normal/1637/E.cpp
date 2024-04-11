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
    sort(a.begin(), a.end());
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
      int ptr = i;
      while (ptr + 1 < n && a[ptr + 1] == a[ptr]) {
        ptr += 1;
      }
      b.emplace_back(ptr - i + 1, a[ptr]);
      i = ptr;
    }
    vector<int> v;
    for (int i = 0; i < (int) b.size(); i++) {
      v.push_back(b[i].first);    
    }           
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<vector<int>> c(n + 1);
    for (int i = 0; i < (int) b.size(); i++) {
      c[b[i].first].push_back(b[i].second);
    }
    map<pair<int, int>, int> g;
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      g[{x, y}] = g[{y, x}] = 1;
    }
    for (int i = 0; i < n; i++) {
      g[{a[i], a[i]}] = 1;
    }                   
    for (int i = 1; i <= n; i++) {
      sort(c[i].rbegin(), c[i].rend());
    }
    long long ans = 0;
    for (int i = 0; i < (int) v.size(); i++) {
      for (int j = i; j < (int) v.size(); j++) {
        for (int x = 0; x < (int) c[v[i]].size(); x++) {
          bool ok = false;
          for (int y = 0; y < (int) c[v[j]].size(); y++) {
            int e1 = c[v[i]][x];
            int e2 = c[v[j]][y];
            if (!g[{e1, e2}]) {
              ans = max(ans, (v[i] + v[j]) * 1LL * (e1 + e2));
              if (y == 0) {
                ok = true;
              }
              break;
            }
          }
          if (ok) {
            break;
          }
        }
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}