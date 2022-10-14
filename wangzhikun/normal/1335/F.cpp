/**
 *    author:  tourist
 *    created: 13.04.2020 17:51:34       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    for (int i = 0; i < h; i++) {
      cin >> c[i];
    }
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
      cin >> s[i];
    }
    vector<vector<int>> deg(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (s[i][j] == 'U') deg[i - 1][j] += 1;
        if (s[i][j] == 'D') deg[i + 1][j] += 1;
        if (s[i][j] == 'L') deg[i][j - 1] += 1;
        if (s[i][j] == 'R') deg[i][j + 1] += 1;
      }
    }
    vector<pair<int, int>> que;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (deg[i][j] == 0) {
          que.emplace_back(i, j);
        }
      }
    }
    for (int b = 0; b < (int) que.size(); b++) {
      int i = que[b].first;
      int j = que[b].second;
      int ni = i;
      int nj = j;
      if (s[i][j] == 'U') ni--;
      if (s[i][j] == 'D') ni++;
      if (s[i][j] == 'L') nj--;
      if (s[i][j] == 'R') nj++;
      if (--deg[ni][nj] == 0) {
        que.emplace_back(ni, nj);
      }
    }
    vector<vector<int>> dist(h, vector<int>(w, -1));
    vector<int> cnt(h * w);
    int A = 0, B = 0;
    for (int si = 0; si < h; si++) {
      for (int sj = 0; sj < w; sj++) {
        if (deg[si][sj] != 0 && dist[si][sj] == -1) {
          que.clear();
          que.emplace_back(si, sj);
          dist[si][sj] = 0;
          int len = 0;
          for (int b = 0; b < (int) que.size(); b++) {
            int mi = que[b].first;
            int mj = que[b].second;
            len += (deg[mi][mj] != 0);
            for (int di = -1; di <= 1; di++) {
              for (int dj = -1; dj <= 1; dj++) {
                if (di * di + dj * dj == 1) {
                  int i = mi + di;
                  int j = mj + dj;
                  if (i < 0 || j < 0 || i >= h || j >= w || dist[i][j] != -1) {
                    continue;
                  }
                  int ni = i;
                  int nj = j;
                  if (s[i][j] == 'U') ni--;
                  if (s[i][j] == 'D') ni++;
                  if (s[i][j] == 'L') nj--;
                  if (s[i][j] == 'R') nj++;
                  if (ni == mi && nj == mj) {
                    que.emplace_back(i, j);
                    dist[i][j] = dist[mi][mj] + 1;
                  }
                }
              }
            } 
          }
          for (int i = 0; i < len; i++) {
            cnt[i] = 0;
          }
          for (int b = 0; b < (int) que.size(); b++) {
            int mi = que[b].first;
            int mj = que[b].second;
            if (c[mi][mj] == '0') {
              cnt[dist[mi][mj] % len] = 1;
            }
          }
          A += len;
          B += accumulate(cnt.begin(), cnt.begin() + len, 0);
        }
      }
    }
    cout << A << " " << B << '\n';
  }
  return 0;
}