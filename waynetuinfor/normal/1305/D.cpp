#include <bits/stdc++.h>
using namespace std;

int Query(int x, int y) {
  cout << "? " << x + 1 << " " << y + 1 << endl;
  int w;
  cin >> w;
  return w - 1;
}

void Answer(int w) {
  cout << "! " << w + 1 << endl;
  exit(0);
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (n == 2) {
    int w = Query(0, 1);
    Answer(w);
  }

  int r = 0;
  while (g[r].size() == 1) r++;

  vector<int> ok(n, 1);

  int a = -1, b = -1;

  function<int(int, int)> Dfs = [&](int x, int p) {
    vector<int> ch;
    for (int u : g[x]) {
      if (u == p) continue;
      int v = Dfs(u, x);
      if (v == -1) continue;
      ch.push_back(v);
    }
    for (int i = 0; i + 1 < ch.size(); i += 2) {
      int w = Query(ch[i], ch[i + 1]);
      for (int k : {x, ch[i], ch[i + 1]}) {
        if (k != w) ok[k] = 0;
      }
    }
    if ((ch.size() & 1) && p != -1) {
      int w = Query(ch.back(), p);
      for (int k : {x, ch.back(), p}) {
        if (k != w) ok[k] = 0;
      }
      return -1;
    }
    if ((ch.size() & 1) && p == -1) {
      a = x;
      b = ch.back();
    }
    return x;
  };

  Dfs(r, -1);
  if (a != -1) {
    if (g[a].size() > 1) {
      for (int u : g[a]) {
        if (u != b) {
          int w = Query(b, u);
          for (int k : {a, b, u}) {
            if (k != w) ok[k] = 0;
          }
          break;
        }
      }
    } else {
      for (int u : g[b]) {
        if (u != a) {
          int w = Query(a, u);
          for (int k : {a, b, u}) {
            if (k != w) ok[k] = 0;
          }
          break;
        }
      }
    }
  }
  assert(count(ok.begin(), ok.end(), 1) == 1);
  for (int i = 0; i < n; ++i) {
    if (ok[i] == 1) Answer(i);
  }
  return 0;
}