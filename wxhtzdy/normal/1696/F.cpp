/**
 *    author:  wxhtzdy
 *    created: 26.06.2022 19:38:24
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
  public:
  vector<int> p;
  int n;
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

bool is[100][100][100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;          
    vector<vector<string>> s(n, vector<string>(n));
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        cin >> s[i][j];
        s[j][i] = s[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          is[i][j][k] = false;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          continue;
        }
        for (int k = 0; k < n; k++) {
          if (s[i][j][k] == '1') {
            is[k][i][j] = true;
          }
        }
      }
    }
    auto Valid = [&](vector<int> p) {
      dsu d(n);
      for (int i = 0; i < n; i++) {
        d.unite(i, p[i]);
      }
      for (int i = 0; i < n; i++) {
        if (d.get(i) != d.get(0)) {
          return false;
        }
      }
      const int inf = 1e6;
      vector<vector<int>> f(n, vector<int>(n, inf));
      for (int i = 0; i < n; i++) {
        f[i][i] = 0;  
      }       
      for (int i = 0; i < n; i++) {
        f[i][p[i]] = f[p[i]][i] = 1;
      }
      for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            f[i][j] = min(f[i][j], f[i][k] + f[k][j]);  
          }
        }
      }
      for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
          for (int j = i + 1; j < n; j++) {
            if (is[k][i][j] != (f[k][i] == f[k][j])) {
              return false;
            }
          }
        }
      }
      return true;
    };               
    vector<int> ans(n, -1);
    for (int v = 1; v < n; v++) {
      // edge (0, v)    
      vector<int> par(n, -1);
      vector<int> que;
      function<void(int, int)> Add = [&](int v, int pr) {
        que.push_back(v);
        par[v] = pr;
      };
      Add(0, v);
      Add(v, 0);              
      for (int b = 0; b < (int) que.size() && (int) que.size() <= n + 1; b++) {
        int i = que[b]; 
        for (int j = 0; j < n; j++) {
          if (i == j || j == par[i]) {
            continue;
          }    
          if (is[i][par[i]][j]) {
            Add(j, i);
          }
        }
      }
      bool ok = true;   
      if ((int) que.size() == n && count(par.begin(), par.end(), -1) == 0 && Valid(par)) {
        ans = par;
        break;
      }
    }
    if (ans[0] == -1) {
      cout << "No" << '\n';
    } else {
      cout << "Yes" << '\n';
      for (int i = 1; i < n; i++) {
        cout << i + 1 << " " << ans[i] + 1 << '\n';
      }
    }                   
  }                                                          
  return 0;
}