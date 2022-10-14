/**
 *    author:  wxhtzdy
 *    created: 01.08.2022 17:21:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, d12, d23, d13;
    cin >> n >> d12 >> d23 >> d13;
    int len = (d12 + d13 - d23);
    int D12 = d12;
    int D23 = d23;
    int D13 = d13;
    if (len % 2 == 1 || d12 > d23 + d13 || d23 > d12 + d13 || d13 > d23 + d12) {
      cout << "NO" << '\n';
      continue;
    }
    if (d12 == d13 + d23) {
      vector<int> a(n);
      int nxt = 4;
      for (int i = 0; i < n; i++) {
        if (i == 0) {
          a[i] = 1;
        } else if (i == d13) {
          a[i] = 3;
        } else if (i == d12) {
          a[i] = 2;          
        } else {
          a[i] = nxt;
          nxt += 1;
        }
      }
      if (*max_element(a.begin(), a.end()) > n) {
        cout << "NO" << '\n';
        continue;
      }
      cout << "YES" << '\n';
      for (int i = 0; i < n - 1; i++) {
        cout << a[i] << " " << a[i + 1] << '\n';
      }
      continue;
    }
    if (d13 == d12 + d23) {
      vector<int> a(n);
      int nxt = 4;
      for (int i = 0; i < n; i++) {
        if (i == 0) {
          a[i] = 1;
        } else if (i == d13) {
          a[i] = 3;
        } else if (i == d12) {
          a[i] = 2;          
        } else {
          a[i] = nxt;
          nxt += 1;
        }
      }   
      if (*max_element(a.begin(), a.end()) > n) {
        cout << "NO" << '\n';
        continue;
      }
      cout << "YES" << '\n';
      for (int i = 0; i < n - 1; i++) {
        cout << a[i] << " " << a[i + 1] << '\n';
      }
      continue;
    }
    len /= 2;
    vector<pair<int, int>> edges;
    int prv = 1, nxt = 4;
    for (int i = 0; i < len; i++) {
      edges.emplace_back(prv, nxt);
      prv = nxt;
      nxt += 1;
    }
    int lst = prv;    
    d12 -= len;       
    for (int i = 0; i < d12 - 1; i++) {
      edges.emplace_back(prv, nxt);
      prv = nxt;
      nxt += 1;
    }
    edges.emplace_back(prv, 2);
    d13 -= len;
    prv = lst;
    for (int i = 0; i < d13 - 1; i++) {
      edges.emplace_back(prv, nxt);
      prv = nxt;
      nxt += 1;
    }
    edges.emplace_back(prv, 3);
    for (int i = nxt; i <= n; i++) {
      edges.emplace_back(1, i);
    }
    auto Check = [&]() {
      vector<vector<int>> g(n);
      for (int i = 0; i < (int) edges.size(); i++) {
        if (edges[i].first > n) {
          return false;
        }
        if (edges[i].second > n) {
          return false;
        }
        g[edges[i].first - 1].push_back(edges[i].second - 1);
        g[edges[i].second - 1].push_back(edges[i].first - 1);
      }
      vector<int> dep(n);
      function<void(int, int)> Dfs = [&](int v, int pr) {
        for (auto& p : g[v]) {
          if (p != pr) {
            dep[p] = dep[v] + 1;
            Dfs(p, v);
          }
        }
      };
      Dfs(0, 0);           
      if (dep[1] != D12 || dep[2] != D13) {
        return false;
      }
      dep[1] = 0;
      Dfs(1, 1);
      return dep[2] == D23;
    };
    if (Check()) {
      cout << "YES" << '\n';
      for (int i = 0; i < (int) edges.size(); i++) {
        cout << edges[i].first << " " << edges[i].second << '\n';
      }
    } else {
      cout << "NO" << '\n';
    }
  }                                                                    
  return 0;
}