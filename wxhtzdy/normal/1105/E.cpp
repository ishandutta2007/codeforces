// fun fact: ako ti se spava, idi da spavas jer u suprotnom neces naci bug nikad
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<int> t(n);
  vector<int> a(n);
  vector<string> s(n);
  vector<string> vec;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    if (i > 0) {
      a[i] = a[i - 1];
    }
    if (t[i] == 1) {
      a[i] += 1;
    } else {
      cin >> s[i];
      vec.push_back(s[i]);
    }
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  vector<vector<int>> pos(m);
  for (int i = 0; i < n; i++) {
    if (t[i] == 2) {
      int id = lower_bound(vec.begin(), vec.end(), s[i]) - vec.begin();
      pos[id].push_back(i);  
    }
  }
  vector<vector<bool>> g(m, vector<bool>(m, false));
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      vector<int> b;
      int x = 0, y = 0;
      while (x < (int) pos[i].size() || y < (int) pos[j].size()) {
        if (x == (int) pos[i].size()) {
          b.push_back(pos[j][y]);
          y += 1;
        } else if (y == (int) pos[j].size()) {
          b.push_back(pos[i][x]);
          x += 1;
        } else {
          if (pos[i][x] < pos[j][y]) {
            b.push_back(pos[i][x]);
            x += 1;
          } else {
            b.push_back(pos[j][y]);
            y += 1;
          }
        }
      }
      bool ok = true;         
      for (int q = 0; q + 1 < (int) b.size(); q++) {
        if (a[b[q]] == a[b[q + 1]] && s[b[q]] != s[b[q + 1]]) {
          ok = false;
        }
      }
      g[i][j] = g[j][i] = ok;
    }
  }
  if (m <= 20) {
    int ans = 1;
    for (int i = 0; i < (1 << m); i++) {
      bool ok = true;
      int cnt = 0;
      for (int x = 0; x < m; x++) {
        if (!(i & (1 << x))) {
          continue;
        }
        cnt += 1;
        for (int y = x + 1; y < m; y++) {
          if (!(i & (1 << y))) {
            continue;
          }
          if (!g[x][y]) {
            ok = false;
          }
        }
      }
      if (ok) {           
        ans = max(ans, cnt);
      }
    }
    cout << ans << '\n';
    return 0;
  }
  int L = 20;
  int R = m - 20;
  vector<int> dp(1 << L);
  for (int i = 0; i < (1 << L); i++) {
    bool ok = true;
    int cnt = 0;
    for (int x = 0; x < L; x++) {
      if (!(i & (1 << x))) {
        continue;
      }
      cnt += 1;
      for (int y = x + 1; y < L; y++) {
        if (!(i & (1 << y))) {
          continue;
        }
        if (!g[x][y]) {
          ok = false;
        }
      }
    }
    if (ok) {           
      dp[i] = cnt;
    }
  }  
  for (int i = 0; i < (1 << L); i++) {
    for (int j = 0; j < L; j++) {
      if (!(i & (1 << j))) {
        dp[i ^ (1 << j)] = max(dp[i], dp[i ^ (1 << j)]);
      }
    }
  }
  int ans = 1;
  for (int m = 0; m < (1 << R); m++) {
    int q = (1 << L) - 1;
    bool ok = true;
    int cnt = 0;
    for (int x = 0; x < R; x++) {
      if (!(m & (1 << x))) {
        continue;
      }
      cnt += 1;
      for (int y = x + 1; y < R; y++) {
        if (!(m & (1 << y))) {
          continue;
        }
        if (!g[x + L][y + L]) {
          ok = false;
        }
      }
    }  
    if (!ok) {
      continue;
    }
    for (int i = 0; i < R; i++) {
      if (!(m & (1 << i))) {
        continue;
      }
      int id = L + i;
      for (int j = 0; j < L; j++) {
        if (!g[id][j]) {
          if (q & (1 << j)) {
            q ^= (1 << j);
          }
        }
      }
    }
    ans = max(ans, dp[q] + cnt); 
  }
  cout << ans << '\n';
  return 0;
}