/**
 *    author:  wxhtzdy
 *    created: 01.08.2022 17:52:24
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
    const int L = 25;
    vector<vector<int>> jump(n, vector<int>(L));
    vector<long long> a(n), b(n);   
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {            
      cin >> jump[i][0] >> a[i] >> b[i];
      --jump[i][0];
      g[jump[i][0]].push_back(i);
    }
    vector<int> dep(n);
    function<void(int)> Dfs = [&](int v) {
      for (int u : g[v]) {
        a[u] += a[v];
        b[u] += b[v];
        dep[u] = dep[v] + 1;
        Dfs(u);
      }
    };   
    Dfs(0);
    for (int j = 1; j < L; j++) {
      for (int i = 0; i < n; i++) {
        jump[i][j] = jump[jump[i][j - 1]][j - 1];
      }
    }
    for (int i = 1; i < n; i++) {
      if (b[i] <= a[i]) {
        cout << dep[i] << " ";
        continue;
      }
      int ver = i;
      for (int j = L - 1; j >= 0; j--) {
        if (b[jump[ver][j]] > a[i]) {
          ver = jump[ver][j];
        }
      }
      ver = jump[ver][0];
      cout << dep[ver] << " ";
    }
    cout << '\n';
  }                                                                    
  return 0;
}