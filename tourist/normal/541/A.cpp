#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int mx[N], mid[N];
int t;

void modify(int x, int v, int id) {
  while (x <= t) {
    if (v > mx[x]) {
      mx[x] = v;
      mid[x] = id;
    }
    x = (x | (x - 1)) + 1;
  }
}

int find_max(int x, int &id) {
  int v = -2;
  while (x > 0) {
    if (mx[x] > v) {
      v = mx[x];
      id = mid[x];
    }
    x &= x - 1;
  }
  return v;
}

int sa[N], fa[N];
int sb[N], fb[N], cb[N];
int pred_a[N], last_a[N];
int pred_b[N], last_b[N];
int real_x[N];

int main() {
  int na, nb;
  scanf("%d %d", &na, &nb);
  for (int i = 0; i < na; i++) {
    scanf("%d %d", sa + i, fa + i);
  }
  for (int i = 0; i < nb; i++) {
    scanf("%d %d %d", sb + i, fb + i, cb + i);
  }
  vector < pair <int, int> > e;
  for (int i = 0; i < na; i++) {
    e.push_back(make_pair(sa[i], i));
    e.push_back(make_pair(fa[i], ~i));
  }
  for (int i = 0; i < nb; i++) {
    e.push_back(make_pair(sb[i], i + na));
    e.push_back(make_pair(fb[i], ~(i + na)));
  }
  sort(e.begin(), e.end());
  int esz = e.size();
  t = 0;
  for (int i = 0; i < esz; i++) {
    if (i == 0 || e[i].first != e[i - 1].first) {
      t++;
      real_x[t] = e[i].first;
    }
    int id = e[i].second;
    if (id >= 0) {
      if (id < na) {
        sa[id] = t;
      } else {
        sb[id - na] = t;
      }
    } else {
      id = ~id;
      if (id < na) {
        fa[id] = t;
      } else {
        fb[id - na] = t;
      }
    }
  }
//  for (int i = 0; i < na; i++)  cerr << i << " -> " << sa[i] << " " << fa[i] << endl;
//  for (int i = 0; i < nb; i++)  cerr << i << " -> " << sb[i] << " " << fb[i] << " " << cb[i] << endl;
  long long ans = 0;
  int ax = -1, ay = -1;
  for (int rot = 0; rot < 2; rot++) {
    for (int i = 1; i <= t; i++) {
      last_a[i] = -1;
      last_b[i] = -1;
    }
    for (int i = 0; i < na; i++) {
      pred_a[i] = last_a[sa[i]];
      last_a[sa[i]] = i;
    }
    for (int i = 0; i < nb; i++) {
      pred_b[i] = last_b[sb[i]];
      last_b[sb[i]] = i;
    }
    int rg = -1, rid = -1;
    for (int i = 1; i <= t; i++) {
      int j = last_a[i];
      while (j >= 0) {
        if (fa[j] > rg) {
          rg = fa[j];
          rid = j;
        }
        j = pred_a[j];
      }
      j = last_b[i];
      while (j >= 0) {
        int to = min(rg, fb[j]);
        if (to > sb[j]) {
          long long cur = (real_x[to] - real_x[sb[j]]) * 1LL * cb[j];
          if (rot == 1) {
            cur = (real_x[t - sb[j] + 1] - real_x[t - to + 1]) * 1LL * cb[j];
          }
          if (cur > ans) {
            ans = cur;
            ax = rid;
            ay = j;
          }
        }
        j = pred_b[j];
      }
    }
    for (int i = 0; i < na; i++) {
      sa[i] = t - sa[i] + 1;
      fa[i] = t - fa[i] + 1;
      swap(sa[i], fa[i]);
    }
    for (int i = 0; i < nb; i++) {
      sb[i] = t - sb[i] + 1;
      fb[i] = t - fb[i] + 1;
      swap(sb[i], fb[i]);
    }
  }
  {
    for (int i = 1; i <= t; i++) {
      last_a[i] = -1;
      last_b[i] = -1;
    }
    for (int i = 0; i < na; i++) {
      pred_a[i] = last_a[sa[i]];
      last_a[sa[i]] = i;
    }
    for (int i = 0; i < nb; i++) {
      pred_b[i] = last_b[sb[i]];
      last_b[sb[i]] = i;
    }
    for (int i = 1; i <= t; i++) {
      mx[i] = -1;
      mid[i] = -1;
    }
    for (int i = t; i >= 1; i--) {
      int j = last_a[i];
      while (j >= 0) {
        modify(fa[j], real_x[fa[j]] - real_x[sa[j]], j);
        j = pred_a[j];
      }
      j = last_b[i];
      while (j >= 0) {
        int id = -1;
        int u = find_max(fb[j], id);
        if (u > 0) {
          long long cur = u * 1LL * cb[j];
          if (cur > ans) {
            ans = cur;
            ax = id;
            ay = j;
          }
        }
        j = pred_b[j];
      }
    }
  }
  cout << ans << endl;
  if (ans > 0) {
    cout << (ax + 1) << " " << (ay + 1) << endl;
  }
  return 0;
}