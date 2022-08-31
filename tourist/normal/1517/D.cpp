/**
 *    author:  tourist
 *    created: 23.04.2021 17:50:32       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, k;
  cin >> h >> w >> k;
  vector<vector<int>> hor(h, vector<int>(w - 1));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w - 1; j++) {
      cin >> hor[i][j];
    }
  }
  vector<vector<int>> ver(h - 1, vector<int>(w));
  for (int i = 0; i < h - 1; i++) {
    for (int j = 0; j < w; j++) {
      cin >> ver[i][j];
    }
  }
  vector<vector<int>> ans(h, vector<int>(w, 0));
  if (k % 2 == 1) {
    ans.assign(h, vector<int>(w, -1));
  } else {
    vector<vector<int>> new_ans(h, vector<int>(w, 0));
    for (int it = 0; it < k / 2; it++) {
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          new_ans[i][j] = (int) 1e9;
          if (i > 0) {
            new_ans[i][j] = min(new_ans[i][j], ans[i - 1][j] + 2 * ver[i - 1][j]);
          }
          if (j > 0) {
            new_ans[i][j] = min(new_ans[i][j], ans[i][j - 1] + 2 * hor[i][j - 1]);
          }
          if (i < h - 1) {
            new_ans[i][j] = min(new_ans[i][j], ans[i + 1][j] + 2 * ver[i][j]);
          }
          if (j < w - 1) {
            new_ans[i][j] = min(new_ans[i][j], ans[i][j + 1] + 2 * hor[i][j]);
          }
        }
      }
      swap(ans, new_ans);
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j > 0) {
        cout << " ";
      }
      cout << ans[i][j];
    }
    cout << '\n';
  }
  return 0;
}