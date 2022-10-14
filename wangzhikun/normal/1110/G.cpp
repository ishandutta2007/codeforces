/**
 *    author:  tourist
 *    created: 07.02.2019 17:24:41       
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
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    string s;
    cin >> s;
    vector<int> vers(1, 0);
    vector<int> diam;
    for (int rot = 0; rot < 2; rot++) {
      vector<int> pr(n, -1);
      vector<int> was(n, 0);
      vector<int> que(1, vers.back());
      was[que[0]] = 1;
      for (int b = 0; b < (int) que.size(); b++) {
        for (int j : g[que[b]]) {
          if (!was[j]) {
            was[j] = was[que[b]] + 1;
            pr[j] = que[b];
            que.push_back(j);
          }
        }
      }
      int id = 0;
      for (int i = 0; i < n; i++) {
        if (was[i] > was[id]) {
          id = i;
        }
      }
      vers.push_back(id);
      diam.assign(1, id);
      while (pr[id] != -1) {
        id = pr[id];
        diam.push_back(id);
      }
    }
    if (n < 3) {
      cout << "Draw" << '\n';
      continue;
    }
    if (n == 3) {
      cout << (count(s.begin(), s.end(), 'W') >= 2 ? "White" : "Draw") << '\n';
      continue;
    }
    if (n == 4) {
      if (diam.size() == 3) {
        cout << (count(s.begin(), s.end(), 'W') >= 1 ? "White" : "Draw") << '\n';
      } else {
        cout << ((s[diam[1]] == 'W' || s[diam[2]] == 'W') ? "White" : "Draw") << '\n';
      }
      continue;
    }
    int sz = (int) diam.size();
    if (sz <= n - 3) {
      cout << "White" << '\n';
      continue;
    }
    vector<int> in_diam(n, -1);
    for (int i = 0; i < sz; i++) {
      in_diam[diam[i]] = i;
    }
    int win = 0;
    for (int i = 1; i < sz - 1; i++) {
      if (s[diam[i]] == 'W') {
        win = 1;
        break;
      }
    }
    if (win) {
      cout << "White" << '\n';
      continue;
    }
    int c0 = (s[diam[0]] == 'W');
    int c1 = (s[diam[sz - 1]] == 'W');
    for (int i = 0; i < n; i++) {
      if (in_diam[i] == -1) {
        if (s[i] == 'W') {
          win = 1;
          break;
        }
        if (g[i].size() > 1) {
          win = 1;
          break;
        }
        int j = g[i][0];
        if (in_diam[j] == 1) {
          c0++;
        } else {
          if (in_diam[j] == sz - 2) {
            c1++;
          } else {
            win = 1;
            break;
          }
        }
      }
    }
    if (win || c0 >= 2 || c1 >= 2 || (c0 + c1 == 2 && sz % 2 == 1)) {
      cout << "White" << '\n';
      continue;
    }
    cout << "Draw" << '\n';
  }
  return 0;
}