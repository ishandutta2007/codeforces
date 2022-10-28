#include <bits/stdc++.h>
using namespace std;

const int M = 200000;
const int N = 1000;

vector<array<int, 4>> queries[M];
int edge[M][2], late[N][N];
bool ans[M];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 0; i < m; ++i) {
    for (auto &j : edge[i]) {
      cin >> j;
      --j;
    }
  }

  for (int i = 0; i < q; ++i) {
    int l, r, s, t;
    cin >> l >> r >> s >> t;
    queries[--r].push_back({--l, --s, --t, i});
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      late[i][j] = -1;
    }
  }

  for (int i = 0; i < m; ++i) {
    int u = edge[i][0], v = edge[i][1];
    late[u][u] = late[v][v] = i;
    for (int j = 0; j < n; ++j) {
      late[u][j] = late[v][j] = max(late[u][j], late[v][j]);
    }
    for (auto [l, s, t, id] : queries[i]) {
      ans[id] = (late[t][s] >= l);
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << (ans[i] ? "Yes" : "No") << "\n";
  }
}