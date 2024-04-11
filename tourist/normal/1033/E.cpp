/**
 *    author:  tourist
 *    created: 07.10.2018 21:47:00       
**/
#include <bits/stdc++.h>

using namespace std;

int ask(const vector<int> &v, char c = '?') {
  int sz = (int) v.size();
  if (sz == 0) {
    return 0;
  }
  printf("%c %d\n", c, sz);
  for (int i = 0; i < sz; i++) {
    if (i > 0) {
      printf(" ");
    }
    printf("%d", v[i] + 1);
  }
  printf("\n");
  fflush(stdout);
  if (c == '?') {
    int x;
    scanf("%d", &x);
    return x;
  }
  return -1;
}

int calc(int a, vector<int> v) {
  int x = ask(v);
  v.push_back(a);
  int y = ask(v);
  return y - x;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> pr(n, -1);
  vector<int> color(n, -1);
  color[0] = 0;
  vector<int> que(1, 0);
  for (int b = 0; b < (int) que.size(); b++) {
    int v = que[b];
    vector<int> who;
    for (int i = 0; i < n; i++) {
      if (color[i] == -1) {
        who.push_back(i);
      }
    }
    int cnt = calc(v, who);
    for (int it = 1; it <= cnt; it++) {
      int low = 0, high = (int) who.size() - 1;
      while (low < high) {
        int mid = (low + high) >> 1;
        int now = calc(v, vector<int>(who.begin(), who.begin() + mid + 1));
        if (now >= it) {
          high = mid;
        } else {
          low = mid + 1;
        }
      }
      int u = who[low];
      color[u] = color[v] ^ 1;
      pr[u] = v;
      que.push_back(u);
    }
  }
  assert((int) que.size() == n);
  vector<vector<int>> by(2);
  for (int i = 0; i < n; i++) {
    by[color[i]].push_back(i);
  }
  for (int c = 0; c < 2; c++) {
    int xx = ask(by[c]);
    if (xx == 0) {
      continue;
    }
    int low = 0, high = (int) by[c].size();
    while (low < high) {
      int mid = (low + high) >> 1;
      int x = ask(vector<int>(by[c].begin(), by[c].begin() + mid));
      if (x == 0) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    int v = by[c][low - 1];
    low = 0; high -= 2;
    while (low < high) {
      int mid = (low + high) >> 1;
      int x = calc(v, vector<int>(by[c].begin(), by[c].begin() + mid + 1));
      if (x == 0) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    int u = by[c][low];
    vector<int> pv, pu;
    while (v != u) {
      pv.push_back(v);
      pu.push_back(u);
      v = pr[v];
      u = pr[u];
    }
    reverse(pu.begin(), pu.end());
    vector<int> path;
    for (int w : pv) {
      path.push_back(w);
    }
    path.push_back(v);
    for (int w : pu) {
      path.push_back(w);
    }
    ask(path, 'N');
    return 0;
  }
  ask(by[0], 'Y');
  return 0;
}