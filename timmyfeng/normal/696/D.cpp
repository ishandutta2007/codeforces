#include <bits/stdc++.h>
using namespace std;

using matrix = vector<vector<long long>>;

matrix mul(matrix a, matrix b) {
  int n = a.size();
  matrix c(n, vector<long long>(n, LLONG_MIN));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (min(a[i][j], b[j][k]) > LLONG_MIN) {
          c[i][k] = max(c[i][k], a[i][j] + b[j][k]);
        }
      }
    }
  }
  return c;
}

const int N = 200 + 1;
const int A = 26;

int a[N], value[N], link[N], to[N][A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long l;
  cin >> n >> l;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int m = 1;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    int cur = 0;
    for (auto c : s) {
      if (to[cur][c - 'a'] == 0) {
        to[cur][c - 'a'] = m++;
      }
      cur = to[cur][c - 'a'];
    }
    value[cur] += a[i];
  }

  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int u = que.front();
    int v = link[u];
    que.pop();

    value[u] += value[v];
    for (int i = 0; i < A; ++i) {
      if (to[u][i] == 0) {
        to[u][i] = to[v][i];
      } else {
        link[to[u][i]] = (u == 0) ? 0 : to[v][i];
        que.push(to[u][i]);
      }
    }
  }

  matrix f(m, vector<long long>(m, LLONG_MIN));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < A; ++j) {
      int k = to[i][j];
      f[i][k] = max(f[i][k], (long long) value[k]);
    }
  }

  matrix g(m, vector<long long>(m, LLONG_MIN));
  for (int i = 0; i < m; ++i) {
    g[i][i] = 0;
  }

  while (l > 0) {
    if (l % 2 == 1) {
      g = mul(g, f);
    }
    f = mul(f, f);
    l /= 2;
  }

  cout << *max_element(g[0].begin(), g[0].end()) << "\n";
}