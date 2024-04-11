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

using namespace std;

const int N = 400010;

vector < pair <int, int> > b;
int a[N], s[N], pz[N], g[N], ng[N], lcp[N], d[20][N];
int m, n, i, j, k;
int ma[N], ml[N], mr[N], ans[N];

void modify(int q, int v) {
  ma[q] = v;
  int x = q;
  while (x <= m) {
    if (v < ml[x]) ml[x] = v;
    x = (x | (x-1))+1;
  }
  x = q;
  while (x > 0) {
    if (v < mr[x]) mr[x] = v;
    x &= x-1;
  }
}

int findmin(int ll, int rr) {
  if (ll > rr) return (int)1e9;
  int res = (int)1e9, x = ll;
  while ((x | (x-1))+1 <= rr) {
    if (mr[x] < res) res = mr[x];
    x = (x | (x-1))+1;
  }
  if (ma[x] < res) res = ma[x];
  x = rr;
  while ((x & (x-1)) >= ll) {
    if (ml[x] < res) res = ml[x];
    x &= x-1;
  }
  return res;
}

int ke;
int e[N], es[N], ef[N], ew[N], sum[N], last[N], pred[N];

void addev(int u, int ss, int ff, int wh) {
  e[ke] = u;
  es[ke] = ss;
  ef[ke] = ff;
  ew[ke] = wh;
  ke++;
}

void addevent(int lower, int upper, int ss, int ff, int wh) {
  addev(upper, ss, ff, wh);
  if (lower > 0) addev(lower-1, ss, ff, ~wh);
}

int main() {
//  freopen("in","r",stdin);
//  freopen("out","w",stdout);
  scanf("%d", &n);
  for (i=0;i<n;i++) scanf("%d", s+i);
  for (i=0;i<n-1;i++) s[i] = s[i+1]-s[i];
  n--;
  for (i=n;i<2*n;i++) s[i] = -s[i-n];
  b.clear();
  for (i=0;i<2*n;i++) b.push_back(make_pair(s[i], i));
  sort(b.begin(), b.end());
  int kg = 0;
  i = 0;
  while (i < 2*n) {
    j = i;
    while (j < 2*n && b[j].first == b[i].first) j++;
    for (k=i;k<j;k++) {
      a[k] = b[k].second;
      pz[a[k]] = k;
      g[k] = kg;
    }
    kg++;
    i = j;
  }
  int step = 1, it = 0;
  while (kg < 2*n) {
    for (i=0;i<2*n;i++) d[it][a[i]] = g[i];
    it++;
    int nkg = 0;
    i = 0;
    while (i < 2*n) {
      j = i;
      while (j < 2*n && g[i] == g[j]) j++;
      b.clear();
      for (k=i;k<j;k++)
        if (a[k]+step < 2*n) b.push_back(make_pair(g[pz[a[k]+step]], a[k]));
        else b.push_back(make_pair(-1, a[k]));
      sort(b.begin(), b.end());
      for (k=0;k<j-i;k++) a[i+k] = b[k].second;
      for (k=i;k<j;k++) {
        if (k == i || b[k-i].first != b[k-i-1].first) nkg++;
        ng[k] = nkg-1;
      }
      i = j;
    }
    for (i=0;i<2*n;i++) pz[a[i]] = i;
    for (i=0;i<2*n;i++) g[i] = ng[i];
    kg = nkg;
    step <<= 1;
  }
  for (i=0;i<2*n;i++) {
    int v = 0, x = a[i], y = a[i+1];
    for (j=it-1;j>=0;j--)
      if (x+v < 2*n && y+v < 2*n && d[j][x+v] == d[j][y+v]) v += (1 << j);
    lcp[i] = v;
/*    printf("%d",a[i]);
    for (j=a[i];j<2*n;j++) printf(" %d",s[j]);
    printf("\n");
    printf("%d\n",lcp[i]);
*/
  }
  m = 2*n-1;
  for (i=1;i<=m;i++) ma[i] = ml[i] = mr[i] = (int)1e9;
  for (i=1;i<=m;i++) modify(i, lcp[i-1]);
  int tt;
  scanf("%d", &tt);
  ke = 0;
  for (int qq=0;qq<tt;qq++) {
    int ql, qr;
    scanf("%d %d", &ql, &qr);
    if (ql == qr) ans[qq] = n; else {
      ans[qq] = 0;
      int x = pz[ql-1], ll, rr, mid;
      ll = x-1; rr = m-1;
      while (ll < rr) {
        mid = (ll+rr+1) >> 1;
        if (findmin(x+1,mid+1) >= qr-ql) ll = mid;
        else rr = mid-1;
      }
      int upper = ll+1;
      ll = 0; rr = x;
      while (ll < rr) {
        mid = (ll+rr) >> 1;
        if (findmin(mid+1,x) >= qr-ql) rr = mid;
        else ll = mid+1;
      }
      int lower = ll;
      int ss = 1, ff = ql-(qr-ql+1);
      if (ss <= ff) addevent(lower, upper, ss+n-1, ff+n-1, qq);
      ss = qr+1; ff = n-(qr-ql+1)+2;
      if (ss <= ff) addevent(lower, upper, ss+n-1, ff+n-1, qq);
    }
  }
  for (i=0;i<2*n;i++) last[i] = -1;
  for (i=0;i<ke;i++) {
    pred[i] = last[e[i]];
    last[e[i]] = i;
  }
  memset(sum,0,sizeof(sum));
  for (i=0;i<2*n;i++) {
    int x = a[i]+1;
    while (x <= 2*n) {
      sum[x]++;
      x = (x | (x-1))+1;
    }
    j = last[i];
    while (j >= 0) {
      x = ef[j]+1;
      while (x > 0) {
        if (ew[j] >= 0) ans[ew[j]] += sum[x];
        else ans[~ew[j]] -= sum[x];
        x &= x-1;
      }
      x = es[j];
      while (x > 0) {
        if (ew[j] >= 0) ans[ew[j]] -= sum[x];
        else ans[~ew[j]] += sum[x];
        x &= x-1;
      }
      j = pred[j];
    }
  }
  for (int qq=0;qq<tt;qq++) printf("%d\n", ans[qq]);
  return 0;
}