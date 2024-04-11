/**
 *    author:  wxhtzdy
 *    created: 18.09.2022 11:17:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  vector<int> y(m);
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i];
    --x[i]; --y[i];
  }
  vector<vector<int>> a(n);
  int T = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i].resize(x);
    for (int j = 0; j < x; j++) {
      cin >> a[i][j];
      T = max(T, a[i][j]);
      --a[i][j];
    }
  }
  mt19937 rng(time(0));
  while (true) {
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      int sz = (int) a[i].size();
      p[i] = a[i][rng() % sz];
    }
    vector<int> q(T);
    for (int i = 0; i < T; i++) {
      q[i] = (rng() % 2);
    }        
    int cnt = 0;      
    for (int i = 0; i < m; i++) {
      if (q[p[x[i]]] != q[p[y[i]]]) {
        cnt += 1;
      }
    }
    if (cnt * 2 >= m) {
      for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " \n"[i == n - 1];
      }
      for (int i = 0; i < T; i++) {
        cout << q[i] + 1 << " \n"[i == T - 1];
      }
      break;
    }
  }                              
  return 0;
}