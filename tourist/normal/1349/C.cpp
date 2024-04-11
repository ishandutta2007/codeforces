/**
 *    author:  tourist
 *    created: 12.05.2020 15:43:54       
**/
#include <bits/stdc++.h>

using namespace std;

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, -1, 0, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, t;
  cin >> h >> w >> t;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  vector<vector<int>> when(h, vector<int>(w, -1));
  vector<pair<int, int>> que;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      for (int dir = 0; dir < 4; dir++) { 
        int ni = i + di[dir];
        int nj = j + dj[dir];
        if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
          if (s[ni][nj] == s[i][j]) {
            que.emplace_back(i, j);
            when[i][j] = 0;
            break;
          }
        }
      }
    }
  }
  for (int b = 0; b < (int) que.size(); b++) {
    int i = que[b].first;
    int j = que[b].second;
    for (int dir = 0; dir < 4; dir++) { 
      int ni = i + di[dir];
      int nj = j + dj[dir];
      if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
        if (when[ni][nj] == -1) {
          que.emplace_back(ni, nj);
          when[ni][nj] = when[i][j] + 1;
        }
      }
    }
  }
  while (t--) {
    int i, j;
    long long p;
    cin >> i >> j >> p;
    --i; --j;
    if (when[i][j] == -1 || p < when[i][j] || (p - when[i][j]) % 2 == 0) {
      cout << s[i][j] << '\n';
    } else {
      cout << (char) (s[i][j] ^ 1) << '\n';
    }
  }
  return 0;
}