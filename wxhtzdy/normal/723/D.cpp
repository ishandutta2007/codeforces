/**
 *  author: milos
 *  created: 26.12.2020 19:06:38
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int n, m, k;
vector<string> s(N);
vector<vector<bool>> was(N, vector<bool>(N, false));
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnt = 0;

void Dfs(int x, int y) {
  was[x][y] = true;
  cnt++;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !was[nx][ny] && s[nx][ny] == '.') {
      Dfs(nx, ny);
    }
  }
}

void Dfs2(int x, int y) {
  s[x][y] = '*';
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] == '.') {
      Dfs2(nx, ny);
    }
  }
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }  
  for (int i = 0; i < n; i++) {
    if (s[i][0] == '.' && !was[i][0]) {
      Dfs(i, 0);
    }
    if (s[i][m - 1] == '.' && !was[i][m - 1]) {
      Dfs(i, m - 1);
    }
  }
  for (int i = 0; i < m; i++) {
    if (s[0][i] == '.' && !was[0][i]) {
      Dfs(0, i);
    }
    if (s[n - 1][i] == '.' && !was[n - 1][i]) {
      Dfs(n - 1, i);
    }
  }
  vector<pair<int, pair<int, int>>> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!was[i][j] && s[i][j] == '.') {
        cnt = 0;
        Dfs(i, j);
        v.push_back({cnt, {i, j}});
      }
    }
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < (int) v.size() - k; i++) {
    ans += v[i].first;
    Dfs2(v[i].second.first, v[i].second.second);
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    cout << s[i];
    if (i < n - 1) {
      cout << '\n';
    }
  }
  return 0;
}