#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int r1, c1;
  cin >> r1 >> c1;
  --r1, --c1;
  int r2, c2;
  cin >> r2 >> c2;
  --r2, --c2;
  auto Valid = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  };
  if (r1 == r2 && c1 == c2) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
      int ni = r1 + dx[i], nj = c1 + dy[i];
      if (Valid(ni, nj) && s[ni][nj] == '.') {
        cnt++;
      }
    }
    cout << (cnt >= 1 ? "YES" : "NO") << '\n';
    return 0;
  }
  set<tuple<int, int, int>> q;
  q.insert({0, r1, c1});
  const int inf = 1e9;
  vector<vector<int>> dist(n, vector<int>(m, inf));
  dist[r1][c1] = 0;
  while (!q.empty()) {
    int x = get<1>(*q.begin());
    int y = get<2>(*q.begin());
    q.erase(q.begin());
    if ((x != r1 || y != c1) && s[x][y] == 'X') {
      continue;
    }
    for (int i = 0; i < 4;  i++) {
      int ni = x + dx[i], nj = y + dy[i];
      int nd = dist[x][y] + 1;
      if (Valid(ni, nj) && dist[ni][nj] > nd) {
        q.erase({dist[ni][nj], ni, nj});
        dist[ni][nj] = nd;
        q.insert({dist[ni][nj], ni, nj});
      }
    }
  }
  if (dist[r2][c2] == inf) {
    cout << "NO" << '\n';
    return 0;
  }
  int cnt = 0;
  bool ok = false;
  for (int i = 0; i < 4; i++) {
    int ni = r2 + dx[i], nj = c2 + dy[i];
    if (Valid(ni, nj) && dist[ni][nj] != inf && s[ni][nj] == '.') {
      cnt++;
    }
    if (Valid(ni, nj) && dist[ni][nj] != inf && s[ni][nj] == '.') {
      ok |= (dist[ni][nj] > dist[r2][c2]);
    }
  }
  if (s[r2][c2] == 'X' || cnt > 1 || ok) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}