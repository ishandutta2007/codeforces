/**
 *  author: milos
 *  created: 31.12.2020 22:55:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < 2 * n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }         
  for (int i = 0; i < n; i++) {
    if ((int) g[i].size() != 4) {
      cout << -1 << '\n';
      return 0;
    }
    sort(g[i].begin(), g[i].end());
  }
  for (int x : g[0]) {
    for (int y : g[0]) {   
      if (x == y) {
        continue;
      }
      vector<int> ans;            
      ans.push_back(0);
      ans.push_back(x);
      ans.push_back(y);
      vector<int> was(n, false);
      was[0] = was[x] = was[y] = true;
      bool ok = true;
      for (int t = 3; t < n; t++) {
        int i = ans[t - 2], j = ans[t - 1];
        bool found = false;
        for (int z : g[i]) {
          for (int r : g[j]) {
            if (was[z] || was[r]) {
              continue;
            }
            if (z == r) {
              ans.push_back(z);
              was[z] = true;
              found = true;
              break; 
            }
          }
          if (found) {
            break;
          }
        }
        if (!found) {
          ok = false;
          break;  
        }
      }
      if (!ok) {
        continue;
      }
      for (int i = 0; i < (int) ans.size(); i++) {
        vector<int> b;    
        for (int j : {-2, -1, 1, 2}) {
          int z = i + j;
          if (z >= n) {
            z %= n;
          }        
          if (z < 0) {
            z += n;
          }
          b.push_back(ans[z]);
        }
        sort(b.begin(), b.end());
        for (int j = 0; j < 4; j++) {
          if (g[ans[i]][j] != b[j]) {
            ok = false;
            break;
          }
        }
      }
      if (!ok) {
        continue;
      }
      for (int i = 0; i < (int) ans.size(); i++) {
        if (i > 0) {
          cout << " ";
        }
        cout << ans[i] + 1;
      }
      cout << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}