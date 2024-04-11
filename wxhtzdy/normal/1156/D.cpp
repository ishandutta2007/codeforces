#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 5;

vector<vector<long long>> sz(N, vector<long long>(2, 1LL));
vector<vector<int>> p(N, vector<int>(2));

int root(int u, int c) {
  return p[u][c] == u ? u : p[u][c] = root(p[u][c], c);
}

void unite(int u, int v, int c) {
  u = root(u, c), v = root(v, c);
  if (sz[u][c] > sz[v][c]) {
    swap(u, v);
  }
  sz[v][c] += sz[u][c];
  p[u][c] = p[v][c];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    p[i][0] = p[i][1] = i;
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    --u, --v;
    unite(u, v, c);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (p[i][0] == i) {
      ans += sz[i][0] * (sz[i][0] - 1);
    }
    if (p[i][1] == i) {
      ans += sz[i][1] * (sz[i][1] - 1);
    }
    ans += (sz[root(i, 0)][0] - 1) * (sz[root(i, 1)][1] - 1);
  }
  cout << ans << '\n';
  return 0;
}