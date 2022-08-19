#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;

const int N = 1234567;

int fin, m;
int ss[N], ff[N], c[N], f[N], s[N], obr[N], pred[N], last[N];

void add(int x, int y, int z, int xx, int yy, int zz) {
  ss[m] = x;
  ff[m] = y;
  c[m] = z;
  f[m] = xx;
  s[m] = yy;
  obr[m] = zz;
  pred[m] = last[x];
  last[x] = m;
  m++;
}

void add(int x, int y, int z, int xx, int yy) {
  add(x, y, z, xx, yy, m + 1);
  add(y, x, 0, 0, -yy, m - 1);
}

int d[N], pr[N];
int kr, r[N];
int x[N];

int expath() {
  for (int i = 0; i <= fin; i++) {
    d[i] = inf;
    pr[i] = -1;
  }
  int b = 0, e = 1;
  x[0] = 0;
  d[0] = 0;
  while (b < e) {
    int j = last[x[b]];
    while (j >= 0) {
      if (c[j] > f[j] && d[x[b]] + s[j] < d[ff[j]]) {
        d[ff[j]] = d[x[b]] + s[j];
        pr[ff[j]] = j;
        x[e] = ff[j];
        e++;
      }
      j = pred[j];
    }
    b++;
  }
  int p = fin;
  kr = 0;
  while (p > 0) {
    r[kr++] = pr[p];
    p = ss[pr[p]];
  }
  return d[fin];
}

char str[N], word[N];

int main() {
  scanf("%d", &fin);
  scanf("%s", str);
  for (int i = 0; i <= fin; i++) {
    last[i] = -1;
  }
  m = 0;
  for (int i = 0; i < fin; i++) {
    add(i, i + 1, 100, 0, 0);
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int cost;
    scanf("%s %d", word, &cost);
    int wlen = strlen(word);
    for (int pos = 0; pos + wlen <= fin; pos++) {
      bool match = true;
      for (int j = 0; j < wlen; j++) {
        if (word[j] != str[pos + j]) {
          match = false;
          break;
        }
      }
      if (match) {
        add(pos, pos + wlen, 1, 0, -cost);
      }
    }
  }
  int xx;
  scanf("%d", &xx);
  int ans = 0;
  for (int it = 0; it < xx; it++) {
    ans += expath();
    for (int j = 0; j < kr; j++) {
      f[r[j]]++;
      f[obr[r[j]]]--;
    }
  }
  printf("%d\n", -ans);
  return 0;
}