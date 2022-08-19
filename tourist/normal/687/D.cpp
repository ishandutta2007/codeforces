#include <bits/stdc++.h>

using namespace std;

const int MAX = 500010;

int aa[MAX], bb[MAX], cc[MAX];
int id[MAX];
int a[MAX], b[MAX], c[MAX];

inline bool cmp(int x, int y) {
  return cc[x] > cc[y];
}

const int N = 1010;

int color[N], comp[N], nc[N];
int nv[N][N];

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", aa + i, bb + i, cc + i);
    aa[i]--; bb[i]--;
    id[i] = i;
  }
  sort(id, id + m, cmp);
  for (int i = 0; i < m; i++) {
    a[i] = aa[id[i]];
    b[i] = bb[id[i]];
    c[i] = cc[id[i]];
  }
  while (q--) {
    int from, to;
    scanf("%d %d", &from, &to);
    for (int i = 0; i < n; i++) {
      color[i] = 0;
      comp[i] = i;
      nc[i] = 1;
      nv[i][0] = i;
    }
    from--; to--;
    int ans = -1;
    for (int i = 0; i < m; i++) {
      if (id[i] < from || id[i] > to) {
        continue;
      }
      if (comp[a[i]] == comp[b[i]]) {
        if (color[a[i]] == color[b[i]]) {
          ans = c[i];
          break;
        }
      } else {
        int x = comp[a[i]];
        int y = comp[b[i]];
        if (nc[x] < nc[y]) {
          swap(x, y);
        }
        int inv = (color[a[i]] == color[b[i]]);
        for (int j = 0; j < nc[y]; j++) {
          int ver = nv[y][j];
          comp[ver] = x;
          color[ver] ^= inv;
          nv[x][nc[x]++] = ver;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}