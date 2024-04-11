/**
 *    author:  tourist
 *    created: 24.09.2017 18:26:27       
**/
#include <bits/stdc++.h>

using namespace std;

const int BLOCK = 301;
const int CNT = (100010 + BLOCK - 1) / BLOCK;
const int n = CNT * BLOCK;
const int N = n + 10;

inline void upd(int &a, int b) {
  a = ((a == 0 || b == 0) ? a + b : min(a, b));
}

int a[2][N];
int b[2][CNT];
bool zeros[2][CNT];
vector<int> c[2][CNT];
int sz[2][CNT];
long long sum[CNT];

inline void push(int id) {
  for (int p = 0; p < 2; p++) {
    if (b[p][id] != 0) {
      for (int i = id * BLOCK; i < (id + 1) * BLOCK; i++) {
        upd(a[p][i], b[p][id]);
      }
      b[p][id] = 0;
    }
  }
}

inline void pull(int id) {
  for (int p = 0; p < 2; p++) {
    zeros[p][id] = false;
    for (int i = id * BLOCK; i < (id + 1) * BLOCK; i++) {
      if (a[p][i] == 0) {
        zeros[p][id] = true;
        break;
      }
    }
    if (zeros[p][id]) {
      continue;
    }
    c[p][id].clear();
    for (int i = id * BLOCK; i < (id + 1) * BLOCK; i++) {
      if (a[1 - p][i] != 0) {
        c[p][id].push_back(a[p][i]);
      }
    }
    sz[p][id] = c[p][id].size();
    sort(c[p][id].begin(), c[p][id].end());
  }
  sum[id] = 0;
  for (int i = id * BLOCK; i < (id + 1) * BLOCK; i++) {
    if (a[0][i] > 0 && a[1][i] > 0) {
      sum[id] += a[0][i] + a[1][i];
    }
  }
}

inline void update_block(int id, int p, int k) {
  int old = b[p][id];
  upd(b[p][id], k);
  if (zeros[p][id]) {
    push(id);
    pull(id);
  } else {
    int extra = sz[p][id] - (int) c[p][id].size();
    if (extra > 0 && k < old) {
      sum[id] -= extra * 1LL * (old - k);
    }
    while (!c[p][id].empty() && c[p][id].back() > k) {
      sum[id] -= c[p][id].back() - k;
      c[p][id].pop_back();
    }
  }
}

inline long long get_block(int id) {
  return sum[id];
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int p = 0; p < 2; p++) {
    for (int i = 0; i < n; i++) {
      a[p][i] = 0;
    }
  }
  for (int i = 0; i < n / BLOCK; i++) {
    pull(i);
  }
  while (tt--) {
    int type, from, to;
    scanf("%d %d %d", &type, &from, &to);
    to--;
    if (type == 1) {
      int k;
      scanf("%d", &k);
      int p;
      if (k > 0) {
        p = 0;
      } else {
        p = 1;
        k = -k;
      }
      int fid = from / BLOCK;
      int tid = to / BLOCK;
      push(fid);
      if (fid != tid) {
        push(tid);
      }
      while (from <= to && from / BLOCK == fid) {
        upd(a[p][from], k);
        from++;
      }
      while (from <= to && to / BLOCK == tid) {
        upd(a[p][to], k);
        to--;
      }
      pull(fid);
      if (fid != tid) {
        pull(tid);
      }
      for (int id = fid + 1; id <= tid - 1; id++) {
        update_block(id, p, k);
      }
    } else {
      long long ans = 0;
      int fid = from / BLOCK;
      int tid = to / BLOCK;
      push(fid);
      if (fid != tid) {
        push(tid);
      }
      while (from <= to && from / BLOCK == fid) {
        if (a[0][from] > 0 && a[1][from] > 0) {
          ans += a[0][from] + a[1][from];
        }
        from++;
      }
      while (from <= to && to / BLOCK == tid) {
        if (a[0][to] > 0 && a[1][to] > 0) {
          ans += a[0][to] + a[1][to];
        }
        to--;
      }
      pull(fid);
      if (fid != tid) {
        pull(tid);
      }
      for (int id = fid + 1; id <= tid - 1; id++) {
        ans += get_block(id);
      }
      printf("%I64d\n", ans);
    }
  }
  cerr << "time = " << clock() << " ms" << endl;
  return 0;
}