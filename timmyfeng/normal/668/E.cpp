#include <bits/stdc++.h>
using namespace std;

const int N = 2000;

struct Formula {

  static int norm(int u) {
    return (u < 0) ? -2 * u - 1 : 2 * u - 2;
  }

  vector<bitset<N>> adj;
  vector<int> ans;
  bool ok;
  int n;

  Formula(int n, int m) : n(n) {
    adj.resize(2 * n);
    ans.assign(n, -1);
    ok = true;

    while (m--) {
      int u, v;
      cin >> u >> v;
      u = norm(u), v = norm(v);
      adj[u ^ 1][v] = adj[v ^ 1][u] = true;
    }

    for (int u = 0; u < 2 * n; ++u) {
      adj[u][u] = true;
    }

    for (int k = 0; k < 2 * n; ++k) {
      for (int i = 0; i < 2 * n; ++i) {
        if (adj[i][k]) {
          adj[i] |= adj[k];
        }
      }
    }

    for (int u = 0; u < 2 * n; ++u) {
      if (adj[u ^ 1][u]) {
        set(u);
      }
    }
  }

  void set(int u) {
    if (ans[u / 2] == -1) {
      ans[u / 2] = u;
      for (int c = 0; c < 2 * n; ++c) {
        if (adj[u][c]) {
          set(c);
        }
      }
    } else if (ans[u / 2] != u) {
      ok = false;
    }
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m1, m2;
  cin >> n >> m1 >> m2;

  Formula f1(n, m1), f2(n, m2);

  if (f1.ok && f2.ok) {
    for (int u = 0; u < n; ++u) {
      if (f1.ans[u] != f2.ans[u]) {
        int x = (f1.ans[u] == -1) ? f2.ans[u] ^ 1 : f1.ans[u] ^ 1;
        f1.set(x), f2.set(x);
        break;
      }
    }
  }

  if (f1.ok && f2.ok) {
    for (int u = 0; u < 2 * n; ++u) {
      if (f1.ans[u / 2] == -1 && f2.ans[u / 2] == -1) {
        for (int v = 0; v < 2 * n; ++v) {
          if (f1.ans[v / 2] == -1 && f2.ans[v / 2] == -1) {
            if (f1.adj[u][v] != f2.adj[u][v]) {
              f1.set(u), f1.set(v ^ 1);
              f2.set(u), f2.set(v ^ 1);
            }
          }
        }
      }
    }

  }

  if (f1.ok == f2.ok) {
    cout << "SIMILAR\n";
  } else {
    Formula f = (f1.ok) ? f1 : f2;
    for (int u = 0; u < n; ++u) {
      if (f.ans[u]) {
        f.set(2 * u);
      }
      cout << 1 - f.ans[u] % 2 << " ";
    }
    cout << "\n";
  }
}