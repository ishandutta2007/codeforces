/**
 *    author:  milos
 *    created: 05.02.2021 15:48:54       
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
      --a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      --b[i];
    }
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
      cin >> c[i];
      --c[i];
    }
    // poslednjeg na tacno
    // sve koje necu bojim na njega
    vector<int> ans;
    vector<vector<int>> g(n);
    int lst = c[m - 1];
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        g[b[i]].push_back(i);  
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        g[b[i]].push_back(i); 
      }
    }
    vector<int> id(n, 0);
    if ((int) g[lst].size() == 0) {
      cout << "NO" << '\n';
      continue;
    }
    id[lst]++;
    for (int i = 0; i < m - 1; i++) {
      if ((int) id[c[i]] >= (int) g[c[i]].size()) {
        ans.push_back(g[lst][0]);  
      } else {
        ans.push_back(g[c[i]][id[c[i]]]);
        id[c[i]]++;
      }
    }
    ans.push_back(g[lst][0]);                     
    bool ok = true;
    assert((int) ans.size() == m);
    for (int i = 0; i < m; i++) {
      a[ans[i]] = c[i];  
    }
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        ok = false;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i : ans) {
      cout << i + 1 << " ";
    }
    cout << '\n';
  }
  return 0;
}