// min caselle da bloccare per otturare tutti i percorsi da (1, 1) a (n, m)
// idee:

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, p, t, n, m, res, x, y;
bool visited[1000010], visitedr[1000010];
vector<long long> adj[1000010], adjr[1000010];

long long vl(long long a, long long b) {
  return m * (a - 1) + b;
}

void dfs(int s) {
  if (visited[s]) {
    return;
  }
  visited[s] = true;
  for (auto u : adj[s]) {
    dfs(u);
  }
}

void dfsr(int s) {
  if (visitedr[s]) {
    return;
  }
  visitedr[s] = true;
  for (auto u : adjr[s]) {
    dfsr(u);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> m;

  y = 0;

  if (n < m) {
    x = n;
    n = m;
    m = x;
    y = 1;
  }

  char mt[n + 1][m + 1];

  if (y == 0) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        cin >> mt[i][j];
      }
    }
  } else {
    for (i = 1; i <= m; i++) {
      for (j = 1; j <= n; j++) {
        cin >> mt[j][i];
      }
    }
  }

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (mt[i][j] == '.') {
        if (i != 1) {
          if (mt[i - 1][j] == '.') {
            x = vl(i - 1, j);
            y = vl(i, j);
            adj[x].push_back(y);
            adjr[y].push_back(x);
          }
        }
        if (j != 1) {
          if (mt[i][j - 1] == '.') {
            x = vl(i, j - 1);
            y = vl(i, j);
            adj[x].push_back(y);
            adjr[y].push_back(x);
          }
        }
      }
    }
  }

  res = 2;
  dfs(1);
  dfsr(m * n);
  for (i = 1; i <= n + m - 3; i++) {
    k = 0;
    for (j = max((long long)0, i - n + 1); j < m; j++) {
      x = vl(i - j + 1, j + 1);
      if (x < 0) {
        // cout << i << ' ' << j << ' ' << x << endl;
      } else {
        if (visited[x] == true && visitedr[x] == true) {
          k++;
        }
      }
    }
    res = min(k, res);
  }

  cout << res;

  return 0;
}