#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector<int> a(N), b(N), sz(N, 0);
vector<vector<int>> g(N);

void Dfs(int x) {
  if ((int) g[x].size() == 0) {
    sz[x] = 1;
    return;
  }
  for (int c : g[x]) {
    Dfs(c);
    sz[x] += sz[c];
  }
}

int Solve(int u) {
  if ((int) g[u].size() == 0) {
    return 1;
  }
  int ans = 0;
  if (a[u] == 1) {
    for (int c : g[u]) {
      int tr = Solve(c) + sz[u] - sz[c];
      ans = max(ans, tr);
    }
    return ans;
  }
  for (int c : g[u]) {
    ans += Solve(c) - 1;
  }
  return ans + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> b[i];
    b[i]--;
    g[b[i]].push_back(i);
  }
  Dfs(0);
  cout << Solve(0) << '\n';
  return 0;
}