#include <bits/stdc++.h>

using namespace std;

const int N = 1200010;

int t, mx[N];

inline void modify(int x, int v) {
  while (x <= t) {
    if (v > mx[x]) {
      mx[x] = v;
    }
    x = (x | (x - 1)) + 1;
  }
}

inline int find_max(int x) {
  int v = 0;
  while (x > 0) {
    if (mx[x] > v) {
      v = mx[x];
    }
    x &= x - 1;
  }
  return v;
}

pair <int, int> ev[N];
int pos[N], value[N], with[N];
int dpleft[N], dpright[N];
vector <int> qs[N];
vector <int> who[N];
int h[N];
bool all[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", h + i);
    ev[i] = make_pair(h[i], i);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", pos + i, value + i);
    pos[i]--;
    ev[n + i] = make_pair(value[i], ~i);
    with[i] = 1;
  }
  sort(ev, ev + n + m);
  t = 0;
  for (int i = 0; i < n + m; i++) {
    if (i == 0 || ev[i].first != ev[i - 1].first) {
      t++;
    }
    int id = ev[i].second;
    if (id >= 0) {
      h[id] = t;
    } else {
      value[~id] = t;
    }
  }
  for (int i = 0; i < n; i++) {
    qs[i].clear();
  }
  for (int i = 0; i < m; i++) {
    qs[pos[i]].push_back(i);
  }
  for (int i = 1; i <= t; i++) {
    mx[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    dpleft[i] = find_max(h[i] - 1) + 1;
    int sz = qs[i].size();
    for (int j = 0; j < sz; j++) {
      int qid = qs[i][j];
      with[qid] += find_max(value[qid] - 1);
    }
    modify(h[i], dpleft[i]);
  }
  for (int i = 1; i <= t; i++) {
    mx[i] = 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    dpright[i] = find_max(t - h[i]) + 1;
    int sz = qs[i].size();
    for (int j = 0; j < sz; j++) {
      int qid = qs[i][j];
      with[qid] += find_max(t - value[qid]);
    }
    modify(t - h[i] + 1, dpright[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dpleft[i]);
  }
  for (int i = 1; i <= ans; i++) {
    who[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int total = dpleft[i] + dpright[i] - 1;
    if (total != ans) {
      continue;
    }
    who[dpleft[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    all[i] = false;
  }
  for (int i = 1; i <= ans; i++) {
    int sz = who[i].size();
    if (sz != 1) {
      continue;
    }
    all[who[i][0]] = true;
  }
  for (int i = 0; i < m; i++) {
    int res = with[i];
    if (all[pos[i]]) {
      res = max(res, ans - 1);
    } else {
      res = max(res, ans);
    }
    printf("%d\n", res);
  }
  return 0;
}