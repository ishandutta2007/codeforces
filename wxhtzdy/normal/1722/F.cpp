/**
 *    author:  wxhtzdy
 *    created: 13.10.2022 15:40:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '.') {
          continue;
        }
        vector<pair<int, int>> que;
        que.emplace_back(i, j);
        s[i][j] = '.';
        for (int b = 0; b < (int) que.size(); b++) {
          int x = que[b].first;
          int y = que[b].second;
          for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
              int nx = x + dx;
              int ny = y + dy;
              if (nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] == '*') {
                s[nx][ny] = '.';
                que.emplace_back(nx, ny); 
              }
            }
          }
        }
        if (que.size() != 3) {
          ok = false;
        } else {
          set<int> sx;
          set<int> sy;
          for (auto& p : que) {
            sx.insert(p.first);
            sy.insert(p.second);
          }
          if ((int) sx.size() != 2 || (int) sy.size() != 2) {
            ok = false;
          }
        }
      } 
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}