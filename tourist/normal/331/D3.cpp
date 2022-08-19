#include <iostream>
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
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const long long inf = (long long)1e17;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const char dir[4] = {'U', 'R', 'D', 'L'};
inline int mabs(int x) { return (x > 0 ? x : -x); }
const int N = 400010;

int arr[N];
long long when[N], dist[N], qt[N];
int pv[55][N];
long long pt[55][N];
int xa[N], ya[N], xb[N], yb[N], arrd[N];
int wx[N], wy[N], wd[N];
int n, b, q;
bool swapx[N], swapy[N];
int ke;
int e[N], el[N], er[N], en[N], rght[N];
bool good[N];

void Sort(int l, int r) {
  int i = l, j = r;
  int x = e[(l+r) >> 1];
  int xx = el[(l+r) >> 1];
  do {
    while (e[i] < x || e[i] == x && el[i] > xx) i++;
    while (x < e[j] || x == e[j] && xx > el[j]) j--;
    if (i <= j) {
      int tmp = e[i]; e[i] = e[j]; e[j] = tmp;
      tmp = el[i]; el[i] = el[j]; el[j] = tmp;
      tmp = er[i]; er[i] = er[j]; er[j] = tmp;
      tmp = en[i]; en[i] = en[j]; en[j] = tmp;
      i++; j--;
    }
  } while (i <= j);
  if (l < j) Sort(l, j);
  if (i < r) Sort(i, r);
}

bool push[N];
int tree[N];

void build(int x, int l, int r) {
  push[x] = false;
  tree[x] = 0;
  if (l < r) {
    build(x+x, l, (l+r) >> 1);
    build(x+x+1, ((l+r) >> 1)+1, r);
  }
}

void put(int x, int l, int r, int ll, int rr, int v) {
//  printf("put %d %d %d %d %d %d\n", x, l, r, ll, rr, v);
  if (l >= ll && r <= rr) {
    push[x] = true;
    tree[x] = v;
    return;
  }
  if (push[x]) {
    push[x+x] = true;
    push[x+x+1] = true;
    tree[x+x] = tree[x];
    tree[x+x+1] = tree[x];
    push[x] = false;
  }
  int y = (l+r) >> 1;
  if (ll <= y) put(x+x, l, y, ll, rr, v);
  if (rr > y) put(x+x+1, y+1, r, ll, rr, v);
}

int get(int x, int l, int r, int p) {
//  printf("get %d %d %d %d\n", x, l, r, p);
  if (l == r || push[x]) return tree[x];
  int y = (l+r) >> 1;
  if (p <= y) return get(x+x, l, y, p);
  return get(x+x+1, y+1, r, p);
}

void get_next_all() {
  for (int i=1;i<=n;i++) {
    swapx[i] = false;
    swapy[i] = false;
    if (xa[i] > xb[i]) { int tmp = xa[i]; xa[i] = xb[i]; xb[i] = tmp; swapx[i] = true; }
    if (ya[i] > yb[i]) { int tmp = ya[i]; ya[i] = yb[i]; yb[i] = tmp; swapy[i] = true; }
  }
  for (int i=1;i<=n+q;i++) {
    if (wx[i] < 0 || wy[i] < 0 || wx[i] > b || wy[i] > b) {
      good[i] = false;
      arr[i] = 0;
    }
    else good[i] = true;
  }
  
  // part 1

  {
    for (int i=1;i<=n;i++) {
      e[i-1] = xa[i];
      el[i-1] = ya[i];
      er[i-1] = yb[i];
      en[i-1] = i;
      rght[i] = xb[i];
    }
    ke = n;
    for (int i=1;i<=n+q;i++) {
      if (wd[i] == 3 && good[i]) {
        e[ke] = wx[i];
        el[ke] = ~wy[i];
        en[ke] = i;
        ke++;
      }
    }
    Sort(0, ke-1);
    build(1, 0, b);
    for (int i=0;i<ke;i++)
      if (el[i] >= 0) {
        put(1, 0, b, el[i], er[i], en[i]);
      } else {
        int num = get(1, 0, b, ~el[i]);
        arr[en[i]] = num;
        when[en[i]] = e[i]-rght[num];
      }
  }

  // part 2

  {
    for (int i=1;i<=n;i++) {
      e[i-1] = -xb[i];
      el[i-1] = ya[i];
      er[i-1] = yb[i];
      en[i-1] = i;
      rght[i] = -xa[i];
//      printf("event %d %d %d %d\n", e[i], el[i], er[i], en[i]);
    }
    ke = n;
    for (int i=1;i<=n+q;i++) {
      if (wd[i] == 1 && good[i]) {
        e[ke] = -wx[i];
        el[ke] = ~wy[i];
        en[ke] = i;
//        printf("event %d %d %d\n", e[ke], el[ke], en[ke]);
        ke++;
      }
    }
    Sort(0, ke-1);
//    for (int i=0;i<ke;i++) printf("sorted event %d %d %d %d\n", e[i], el[i], er[i], en[i]);
    build(1, 0, b);
    for (int i=0;i<ke;i++)
      if (el[i] >= 0) {
        put(1, 0, b, el[i], er[i], en[i]);
      } else {
        int num = get(1, 0, b, ~el[i]);
//        printf("%d\n", num);
        arr[en[i]] = num;
        when[en[i]] = e[i]-rght[num];
      }
  }

  // part 3

  {
    for (int i=1;i<=n;i++) {
      e[i-1] = ya[i];
      el[i-1] = xa[i];
      er[i-1] = xb[i];
      en[i-1] = i;
      rght[i] = yb[i];
    }
    ke = n;
    for (int i=1;i<=n+q;i++) {
      if (wd[i] == 2 && good[i]) {
        e[ke] = wy[i];
        el[ke] = ~wx[i];
        en[ke] = i;
        ke++;
      }
    }
    Sort(0, ke-1);
    build(1, 0, b);
    for (int i=0;i<ke;i++)
      if (el[i] >= 0) {
        put(1, 0, b, el[i], er[i], en[i]);
      } else {
        int num = get(1, 0, b, ~el[i]);
        arr[en[i]] = num;
        when[en[i]] = e[i]-rght[num];
      }
  }

  // part 4

  {
    for (int i=1;i<=n;i++) {
      e[i-1] = -yb[i];
      el[i-1] = xa[i];
      er[i-1] = xb[i];
      en[i-1] = i;
      rght[i] = -ya[i];
//      printf("event %d %d %d %d\n", e[i], el[i], er[i], en[i]);
    }
    ke = n;
    for (int i=1;i<=n+q;i++) {
      if (wd[i] == 0 && good[i]) {
        e[ke] = -wy[i];
        el[ke] = ~wx[i];
        en[ke] = i;
//        printf("event %d %d %d\n", e[ke], el[ke], en[ke]);
        ke++;
      }
    }
    Sort(0, ke-1);
//    for (int i=0;i<ke;i++) printf("sorted event %d %d %d %d\n", e[i], el[i], er[i], en[i]);
    build(1, 0, b);
    for (int i=0;i<ke;i++)
      if (el[i] >= 0) {
        put(1, 0, b, el[i], er[i], en[i]);
      } else {
        int num = get(1, 0, b, ~el[i]);
//        printf("%d\n", num);
        arr[en[i]] = num;
        when[en[i]] = e[i]-rght[num];
      }
  }

  for (int i=1;i<=n+q;i++) {
    if (arr[i] == 0) when[i] = inf;
    if (when[i] < 0) when[i] = 0;
  }
  for (int i=1;i<=n;i++) {
    if (swapx[i]) { int tmp = xa[i]; xa[i] = xb[i]; xb[i] = tmp; }
    if (swapy[i]) { int tmp = ya[i]; ya[i] = yb[i]; yb[i] = tmp; }
  }
}

int main() {
  scanf("%d %d", &n, &b);
  for (int i=1;i<=n;i++) {
    scanf("%d %d %d %d", xa+i, ya+i, xb+i, yb+i);
    if (yb[i] > ya[i]) arrd[i] = 0; else
    if (xb[i] > xa[i]) arrd[i] = 1; else
    if (yb[i] < ya[i]) arrd[i] = 2;
    else arrd[i] = 3;
    wx[i] = xb[i] + dx[arrd[i]];
    wy[i] = yb[i] + dy[arrd[i]];
    wd[i] = arrd[i];
  }
  scanf("%d", &q);
  for (int i=n+1;i<=n+q;i++) {
    char foo;
    scanf("%d %d %c %I64d", wx+i, wy+i, &foo, qt+i);
    wd[i] = 0;
    for (int j=0;j<4;j++)
      if (foo == dir[j]) wd[i] = j;
  }
  get_next_all();
  for (int i=1;i<=n+q;i++) 
    if (arr[i] == 0) dist[i] = inf;
    else dist[i] = mabs(wx[i] - xb[arr[i]]) + mabs(wy[i] - yb[arr[i]]);
//  for (int i=1;i<=n+q;i++) printf("%d %I64d %I64d\n", arr[i], when[i], dist[i]);
  arr[0] = 0;
  when[0] = inf;
  dist[0] = inf;
  for (int i=0;i<=n;i++) pv[0][i] = arr[i], pt[0][i] = dist[i] + 1;
  for (int j=1;j<=50;j++)
    for (int i=0;i<=n;i++) {
      pv[j][i] = pv[j-1][pv[j-1][i]];
      pt[j][i] = pt[j-1][i] + pt[j-1][pv[j-1][i]];
      if (pt[j][i] > inf) pt[j][i] = inf;
    }
  for (int i=n+1;i<=n+q;i++) {
    if (qt[i] <= dist[i]) {
      if (qt[i] <= when[i]) {
        long long ax = wx[i] + dx[wd[i]] * qt[i];
        long long ay = wy[i] + dy[wd[i]] * qt[i];
        if (ax < 0) ax = 0;
        if (ay < 0) ay = 0;
        if (ax > b) ax = b;
        if (ay > b) ay = b;
        printf("%d %d\n", (int)ax, (int)ay);
        continue;
      }
      long long ax = wx[i] + dx[wd[i]] * when[i];
      long long ay = wy[i] + dy[wd[i]] * when[i];
      ax += dx[arrd[arr[i]]] * (qt[i] - when[i]);
      ay += dy[arrd[arr[i]]] * (qt[i] - when[i]);
      if (ax < 0) ax = 0;
      if (ay < 0) ay = 0;
      if (ax > b) ax = b;
      if (ay > b) ay = b;
      printf("%d %d\n", (int)ax, (int)ay);
      continue;
    }
    qt[i] -= dist[i];
    int where = arr[i];
    for (int j=50;j>=0;j--)
      if (pt[j][where] <= qt[i]) {
        qt[i] -= pt[j][where];
        where = pv[j][where];
      }
    if (arr[where] == 0 || qt[i] <= when[where]+1) {
      long long ax = xb[where] + dx[arrd[where]] * qt[i];
      long long ay = yb[where] + dy[arrd[where]] * qt[i];
      if (ax < 0) ax = 0;
      if (ay < 0) ay = 0;
      if (ax > b) ax = b;
      if (ay > b) ay = b;
      printf("%d %d\n", (int)ax, (int)ay);
      continue;
    }
    int ax = xb[where] + dx[arrd[where]] * (when[where]+1);
    int ay = yb[where] + dy[arrd[where]] * (when[where]+1);
    ax += dx[arrd[arr[where]]] * (qt[i] - (when[where]+1));
    ay += dy[arrd[arr[where]]] * (qt[i] - (when[where]+1));
    printf("%d %d\n", ax, ay);
  }
  return 0;
}