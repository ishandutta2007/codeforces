/**
 *    author:  tourist
 *    created: 16.08.2020 18:58:52       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  string mine;
  string goal;
  cin >> mine >> goal;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
  }
  vector<int> perm(k);
  iota(perm.begin(), perm.end(), 0);
  vector<int> my_mask(n + 1);
  vector<int> goal_mask(n + 1);
  for (int i = n; i >= 0; i--) {
    if (i < n) {
      swap(perm[a[i]], perm[b[i]]);
    }
    for (int j = 0; j < k; j++) {
      if (mine[j] == '1') {
        my_mask[i] |= (1 << perm[j]);
      }
    }
    for (int j = 0; j < k; j++) {
      if (goal[j] == '1') {
        goal_mask[i] |= (1 << perm[j]);
      }
    }
  }
  vector<int> que(1 << k);
  vector<int> dist(1 << k, k + 1);
  vector<int> root(1 << k, -1);
  int ans = k + 1;
  int ax = -1, ay = -1;
  for (int i = n - m; i >= 0; i--) {
    int start = goal_mask[i + m];
    if (dist[start] > 0) {
      int qIt = 0;
      int qSz = 1;
      que[0] = start;
      dist[start] = 0;
      root[start] = i + m - 1;
      while (qIt < qSz) {
        int cur = que[qIt++];
        for (int bit = 0; bit < k; bit++) {
          if (dist[cur] + 1 < dist[cur ^ (1 << bit)]) {
            que[qSz++] = cur ^ (1 << bit);
            dist[cur ^ (1 << bit)] = dist[cur] + 1;
            root[cur ^ (1 << bit)] = i + m - 1;
          }
        }
      }
    }
    int now = dist[my_mask[i]];
    if (now < ans) {
      ans = now;
      ax = i;
      ay = root[my_mask[i]];
    }
  }
  cout << k - ans << '\n';
  cout << ax + 1 << " " << ay + 1 << '\n';
  return 0;
}