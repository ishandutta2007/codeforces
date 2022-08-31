#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

const int N = 400010;

int s[28][N];
char v[28][N], p[28][N];
int *ss;
char *vv, *pp;

void modify(int q, int x, int l, int r, int ll, int rr, int t) {
  if (l >= ll && r <= rr) {
    vv[x] = t;
    pp[x] = 1;
    ss[x] = t*(r-l+1);
    return;
  }
  if (pp[x]) {
    vv[x+x] = vv[x+x+1] = vv[x];
    pp[x+x] = pp[x+x+1] = 1;
    if (!vv[x]) ss[x+x] = ss[x+x+1] = 0; else {
      ss[x+x] = (((l+r) >> 1)-l+1);
      ss[x+x+1] = (r-((l+r) >> 1));
    }
    pp[x] = 0;
  }
  int y = (l+r) >> 1;
  if (ll <= y) modify(q, x+x, l, y, ll, rr, t);
  if (rr > y) modify(q, x+x+1, y+1, r, ll, rr, t);
  ss[x] = ss[x+x] + ss[x+x+1];
}

int findsum(int q, int x, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) return ss[x];
  if (pp[x]) {
    vv[x+x] = vv[x+x+1] = vv[x];
    pp[x+x] = pp[x+x+1] = 1;
    if (!vv[x]) ss[x+x] = ss[x+x+1] = 0; else {
      ss[x+x] = (((l+r) >> 1)-l+1);
      ss[x+x+1] = (r-((l+r) >> 1));
    }
    pp[x] = 0;
  }
  int y = (l+r) >> 1, res = 0;
  if (ll <= y) res += findsum(q, x+x, l, y, ll, rr);
  if (rr > y) res += findsum(q, x+x+1, y+1, r, ll, rr);
  ss[x] = ss[x+x] + ss[x+x+1];
  return res;
}

int n, m, i, lo, hi, cnt[255];
char c, st[N];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d", &n, &m);
  scanf("%s", st);
  for (i=0;i<n;i++) {
    pp = p[st[i]-'a'];
    vv = v[st[i]-'a'];
    ss = s[st[i]-'a'];
    modify(st[i]-'a', 1, 0, n-1, i, i, 1);
  }
  while (m--) {
    scanf("%d %d", &lo, &hi);
    lo--; hi--;
    char bad = ' ';
    for (c='a';c<='z';c++) {
      pp = p[c-'a'];
      vv = v[c-'a'];
      ss = s[c-'a'];
      cnt[c] = findsum(c-'a', 1, 0, n-1, lo, hi);
      if (cnt[c] & 1)
        if (bad == ' ') bad = c; else {
          bad = '!';
          break;
        }
    }
    if (bad == '!') continue;
    int oldlo = lo, oldhi = hi;
    for (c='a';c<='z';c++)
      if (cnt[c] > 0) {
        pp = p[c-'a'];
        vv = v[c-'a'];
        ss = s[c-'a'];
        modify(c-'a', 1, 0, n-1, oldlo, oldhi, 0);
        int u = cnt[c]/2;
        if (!u) continue;
        modify(c-'a', 1, 0, n-1, lo, lo+u-1, 1);
        lo += u;
        modify(c-'a', 1, 0, n-1, hi-u+1, hi, 1);
        hi -= u;
      }
    if (bad != ' ') {
      pp = p[bad-'a'];
      vv = v[bad-'a'];
      ss = s[bad-'a'];
      modify(bad-'a', 1, 0, n-1, lo, hi, 1);
    }
  }
  for (i=0;i<n;i++) st[i] = 0;
  for (c='a';c<='z';c++) {
    pp = p[c-'a'];
    vv = v[c-'a'];
    ss = s[c-'a'];
    for (i=0;i<n;i++)
      if (!st[i] && findsum(c-'a', 1, 0, n-1, i, i) == 1) st[i] = c;
  }
  for (i=0;i<n;i++) putchar(st[i]);
  printf("\n");
  return 0;
}