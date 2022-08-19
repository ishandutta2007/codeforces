#include <bits/stdc++.h>

using namespace std;

const int N = 5050;
const int TT = 100010;
const int TT6 = (TT >> 6) + 10;

unsigned long long one = 1, mx[N][TT6], my[N][TT6], mz[N + N][TT6];
vector < pair <int, int> > ex[N], ey[N], ez[N + N];

int com[TT], dir[TT], x[TT], y[TT], len[TT], res[TT];

int kb[1 << 16];

inline int my_popcountll(unsigned long long x) {
  int res = kb[x & 65535];
  x >>= 16;
  res += kb[x & 65535];
  x >>= 16;
  res += kb[x & 65535];
  x >>= 16;
  res += kb[x];
  return res;
}

int main() {
  kb[0] = 0;
  for (int i = 1; i < (1 << 16); i++) {
    kb[i] = kb[i & (i - 1)] + 1;
  }
  int sz, tt;
  scanf("%d %d", &sz, &tt);
  int tt6 = ((tt - 1) >> 6) + 1;
  for (int qq = 0; qq < tt; qq++) {
    scanf("%d", com + qq);
    if (com[qq] == 1) {
      scanf("%d %d %d %d", dir + qq, x + qq, y + qq, len + qq);
    } else {
      scanf("%d %d", x + qq, y + qq);
      res[qq] = 0;
    }
  }
  for (int rot = 0; rot < 2; rot++) {
    for (int i = 0; i <= sz; i++) {
      ex[i].clear();
      ey[i].clear();
      for (int j = 0; j < tt6; j++) {
        mx[i][j] = 0;
        my[i][j] = 0;
      }
    }
    for (int i = 0; i <= sz + sz; i++) {
      ez[i].clear();
      for (int j = 0; j < tt6; j++) {
        mz[i][j] = 0;
      }
    }
    for (int qq = 0; qq < tt; qq++) {
      if (com[qq] == 1) {
        if (dir[qq] == 1) {
          ex[x[qq]].push_back(make_pair(qq, 1));
          ey[y[qq]].push_back(make_pair(qq, 1));
          mz[0][qq >> 6] |= (one << (qq & 63));
          ez[x[qq] + y[qq] + len[qq] + 1].push_back(make_pair(qq, 0));
        }
        if (dir[qq] == 4) {
          mx[0][qq >> 6] |= (one << (qq & 63));
          ex[x[qq] + 1].push_back(make_pair(qq, 0));
          my[0][qq >> 6] |= (one << (qq & 63));
          ey[y[qq] + 1].push_back(make_pair(qq, 0));
          ez[x[qq] + y[qq] - len[qq]].push_back(make_pair(qq, 1));
        }
      }
    }
    for (int xx = 1; xx <= sz; xx++) {
      for (int j = 0; j < tt6; j++) {
        mx[xx][j] |= mx[xx - 1][j];
      }
      int sz = ex[xx].size();
      for (int q = 0; q < sz; q++) {
        int u = ex[xx][q].first;
        int v = ex[xx][q].second;
        if (v == 1) {
          mx[xx][u >> 6] |= (one << (u & 63));
        } else {
          mx[xx][u >> 6] &= (~(one << (u & 63)));
        }
      }
    }
    for (int yy = 1; yy <= sz; yy++) {
      for (int j = 0; j < tt6; j++) {
        my[yy][j] |= my[yy - 1][j];
      }
      int sz = ey[yy].size();
      for (int q = 0; q < sz; q++) {
        int u = ey[yy][q].first;
        int v = ey[yy][q].second;
        if (v == 1) {
          my[yy][u >> 6] |= (one << (u & 63));
        } else {
          my[yy][u >> 6] &= (~(one << (u & 63)));
        }
      }
    }
    for (int zz = 1; zz <= sz + sz; zz++) {
      for (int j = 0; j < tt6; j++) {
        mz[zz][j] |= mz[zz - 1][j];
      }
      int sz = ez[zz].size();
      for (int q = 0; q < sz; q++) {
        int u = ez[zz][q].first;
        int v = ez[zz][q].second;
        if (v == 1) {
          mz[zz][u >> 6] |= (one << (u & 63));
        } else {
          mz[zz][u >> 6] &= (~(one << (u & 63)));
        }
      }
    }
    for (int qq = 0; qq < tt; qq++) {
      if (com[qq] == 2) {
        int z = x[qq] + y[qq];
        int up = (qq >> 6);
        for (int j = 0; j < up; j++) {
          unsigned long long r = mx[x[qq]][j] & my[y[qq]][j] & mz[z][j];
          res[qq] += my_popcountll(r);
        }
        unsigned long long r = mx[x[qq]][up] & my[y[qq]][up] & mz[z][up];
        r &= ((one << (qq & 63)) - 1);
        res[qq] += my_popcountll(r);
      }
    }
    for (int qq = 0; qq < tt; qq++) {
      y[qq] = sz - y[qq] + 1;
      if (dir[qq] <= 2) {
        dir[qq] = 3 - dir[qq];
      } else {
        dir[qq] = 7 - dir[qq];
      }
    }
  }
  for (int qq = 0; qq < tt; qq++) {
    if (com[qq] == 2) {
      printf("%d\n", res[qq]);
    }
  }
  return 0;
}