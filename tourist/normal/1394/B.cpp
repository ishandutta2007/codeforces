/**
 *    author:  tourist
 *    created: 12.08.2020 18:11:50       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int K = 11;

bool can[K][K][K][K];
bool good[K][K];
int in[N][K][K];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> from(m);
  vector<int> to(m);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y; --z;
    from[z] = x;
    to[z] = y;
  }
  vector<vector<int>> out(n);
  for (int i = 0; i < m; i++) {
    out[from[i]].push_back(to[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int z = 1; z <= k; z++) {
      for (int cz = 0; cz < z; cz++) {
        in[i][z][cz] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int sz = (int) out[i].size();
    for (int j = 0; j < sz; j++) {
      in[out[i][j]][sz][j] += 1;
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int ci = 0; ci < i; ci++) {
      for (int j = 1; j <= k; j++) {
        for (int cj = 0; cj < j; cj++) {
          can[i][ci][j][cj] = true;
        }
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int ci = 0; ci < i; ci++) {
      good[i][ci] = true;
    }
  }
  for (int v = 0; v < n; v++) {
    for (int i = 1; i <= k; i++) {
      for (int ci = 0; ci < i; ci++) {
        if (in[v][i][ci] >= 2) {
          good[i][ci] = false;
        }
        if (in[v][i][ci] > 0) {
          for (int j = 1; j < i; j++) {
            for (int cj = 0; cj < j; cj++) {
              if (in[v][j][cj] > 0) {
                can[i][ci][j][cj] = false;
              }
            }
          }
        }
      }
    }
  }
  vector<int> c(k + 1);
  int ans = 0;
  function<void(int)> Dfs = [&](int v) {
    if (v == k + 1) {
      ++ans;
      return;
    }
    c[v] = 0;
    while (c[v] < v) {
      bool ok = good[v][c[v]];
      for (int i = 1; i < v; i++) {
        if (!can[v][c[v]][i][c[i]]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        Dfs(v + 1);
      }
      ++c[v];
    }
  };
  Dfs(1);
  cout << ans << '\n';
  return 0;
}