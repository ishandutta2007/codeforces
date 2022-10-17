#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int N;
  cin >> N;
  vector<vector<vector<bool>>> eq(N, vector<vector<bool>>(N, vector<bool>(N)));
  for (int i = 0; i < N - 1; ++i) {
    for (int j = 0; j < N - i - 1; ++j) {
      string s;
      cin >> s;
      for (int k = 0; k < N; ++k) {
        if (s[k] == '1') {
          eq[i][i + j + 1][k] = true;
          eq[i + j + 1][i][k] = true;
        }
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      eq[i][i][j] = true;
    }
  }
  if (N == 2) {
    if (!eq[0][1][0] && !eq[0][1][1]) {
      cout << "Yes\n";
      cout << 1 << " " << 2 << "\n";
    } else {
      cout << "No\n";
    }
    return;
  }

  // cerr << "debug = " << eq[0][1][2] << endl;

  vector<vector<int>> g(N);
  for (int r = 1; r < N; ++r) {
    vector<int> from(N, -1);
    vector<int> que;
    for (int i = 0; i < N; ++i) {
      g[i].clear();
    }
    // cerr << "try r = " << r << endl;
    for (int j = 1; j < N; ++j) {
      if (eq[r][j][0]) {
        g[0].push_back(j);
        g[j].push_back(0);
        // cerr << 0 << " -> " << j << endl;
        from[j] = 0;
        que.push_back(j);
      }
    }
    for (int it = 0; it < que.size(); ++it) {
      int x = que[it];
      // cerr << "x = " << x << " from = " << from[x] << endl;
      for (int k = 1; k < N; ++k) {
        // cerr << "k = " << k << " eq = " << eq[from[x]][k][x] << " from = " << from[k] << endl;
        if (eq[from[x]][k][x] && from[k] == -1) {
          g[x].push_back(k);
          g[k].push_back(x);
          // cerr << x << " -> " << k << endl;
          from[k] = x;
          que.push_back(k);
        }
      }
    }
    bool ok = true;
    for (int j = 1; j < N; ++j) {
      if (from[j] == -1) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }
    // cerr << "ok r = " << r << endl;
    vector<int> dist(N, -1);
    for (int i = 0; ok && i < N; ++i) {
      fill(dist.begin(), dist.end(), -1);
      dist[i] = 0;
      queue<int> qu;
      qu.push(i);
      while (!qu.empty()) {
        int x = qu.front();
        qu.pop();
        for (int u : g[x]) {
          if (dist[u] == -1) {
            dist[u] = dist[x] + 1;
            qu.push(u);
          }
        }
      }
      for (int j = 0; ok && j < N; ++j) {
        for (int k = 0; ok && k < N; ++k) {
          if ((dist[j] == dist[k]) != eq[j][k][i]) {
            ok = false;
            break;
          }
        }
      }
    }
    if (ok) {
      cout << "Yes\n";
      for (int i = 0; i < N; ++i) {
        for (int u : g[i]) {
          if (i < u) {
            cout << i + 1 << " " << u + 1 << "\n";
          }
        }
      }
      return;
    }
  }
  cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    Solve();
  }
}