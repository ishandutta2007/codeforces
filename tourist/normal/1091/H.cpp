/**
 *    author:  tourist
 *    created: 30.12.2018 19:06:43       
**/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = 200010;
  vector<int> p(MAX);
  iota(p.begin(), p.end(), 0);
  for (int i = 2; i < MAX; i++) {
    if (p[i] == i) {
      for (int j = i + i; j < MAX; j += i) {
        if (p[j] == j) {
          p[j] = i;
        }
      }
    }
  }
  int n, f;
  cin >> n >> f;
  vector<int> is_valid(MAX, 0);
  for (int i = 2; i < MAX; i++) {
    if (p[i] == i || p[i / p[i]] == i / p[i]) {
      if (i != f) {
        is_valid[i] = 1;
      }
    }
  }
  vector<int> g(MAX);
  g[0] = 0;
  vector<vector<int>> who(1);
  who[0].push_back(0);
  for (int i = 1; i < MAX; i++) {
    g[i] = 0;
    while (true) {
      if ((int) who.size() < g[i] + 1) {
        break;
      }
      int any = 0;
      for (int j : who[g[i]]) {
        if (is_valid[i - j]) {
          any = 1;
          break;
        }
      }
      if (!any) {
        break;
      }
      g[i]++;
    }
    if ((int) who.size() < g[i] + 1) {
      who.resize(g[i] + 1);
    }
    who[g[i]].push_back(i);
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    res ^= g[y - x - 1];
    res ^= g[z - y - 1];
  }
  cout << (res == 0 ? "Bob" : "Alice") << '\n';
  cout << (res != 0 ? "Bob" : "Alice") << '\n';
  return 0;
}