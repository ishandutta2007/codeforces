/**
 *    author:  tourist
 *    created: 13.03.2021 12:23:56       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> b(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> b[i][j];
    }
  }
  if (a == b) {
    cout << 0 << '\n';
    return 0;
  }
  vector<int> seq;
  vector<int> deg(w);
  for (int i = 0; i < h - 1; i++) {
    for (int j = 0; j < w; j++) {
      if (b[i][j] > b[i + 1][j]) {
        deg[j] += 1;
      }
    }
  }
  vector<bool> used(h, false);
  vector<int> que;
  auto Use = [&](int i) {
    used[i] = true;
    for (int j = 0; j < w; j++) {
      if (b[i][j] > b[i + 1][j]) {
        deg[j] -= 1;
        if (deg[j] == 0) {
          que.push_back(j);
        }
      }
    }
  };
  for (int j = 0; j < w; j++) {
    if (deg[j] == 0) {
      que.push_back(j);
    }
  }
  for (int bb = 0; bb < (int) que.size(); bb++) {
    int j = que[bb];
    for (int i = 0; i < h - 1; i++) {
      if (!used[i] && b[i][j] != b[i + 1][j]) {
        Use(i);
      }
    }
  }
  vector<int> order(h);
  iota(order.begin(), order.end(), 0);
  reverse(que.begin(), que.end());
  for (int col : que) {
    stable_sort(order.begin(), order.end(), [&](int i, int j) {
      return a[i][col] < a[j][col];
    });
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[order[i]][j] != b[i][j]) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }
  cout << que.size() << '\n';
  for (int i = 0; i < (int) que.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << que[i] + 1;
  }
  cout << '\n';
  return 0;
}