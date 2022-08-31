#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <memory.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int md = 1000000007;

const int N = 600010;

int last[N], pred[N];
pair <int, int> t[N];

char s[N];
int a[N], g[N], pz[N];
int nna[N], ng[N];

int d[25][N];
int lcp[N];

int sum[N][3];

void subtr(int &ans, int *x, int *y) {
  int u = x[0] - y[0];
  for (int j = 1; j < 3; j++) {
    int v = x[j] - y[j];
    u = (long long)u * v % md;
  }
  ans += md - u;
  if (ans >= md) {
    ans -= md;
  }
}

void add(int &ans, int *x, int *y) {
  int u = x[0] - y[0];
  for (int j = 1; j < 3; j++) {
    int v = x[j] - y[j];
    u = (long long)u * v % md;
  }
  ans += u;
  if (ans >= md) {
    ans -= md;
  }
}

char sa[N], sb[N], sc[N];
int type[N];

int pr[N], ne[N];

int result[N];

int main() {
  scanf("%s", sa);
  scanf("%s", sb);
  scanf("%s", sc);
  int na = strlen(sa);
  int nb = strlen(sb);
  int nc = strlen(sc);
  for (int i = 1; i <= na; i++) {
    s[i] = sa[i - 1];
    type[i] = 0;
  }
  s[na + 1] = '#';
  type[na + 1] = -1;
  for (int i = na + 2; i <= na + nb + 1; i++) {
    s[i] = sb[i - na - 2];
    type[i] = 1;
  }
  s[na + nb + 2] = '$';
  type[na + nb + 2] = -1;
  for (int i = na + nb + 3; i <= na + nb + nc + 2; i++) {
    s[i] = sc[i - na - nb - 3];
    type[i] = 2;
  }
  s[na + nb + nc + 3] = 0;
  int n = strlen(s + 1);
  for (int c = 0; c < 255; c++) last[c] = 0;
  for (int i = 1; i <= n; i++) {
    pred[i] = last[s[i]];
    last[s[i]] = i;
  }
  int kg = 0, nn = 0;
  for (int c = 0; c < 255; c++)
    if (last[c] > 0) {
      kg++;
      int j = last[c];
      while (j > 0) {
        nn++;
        a[nn] = j;
        g[nn] = kg;
        pz[j] = nn;
        j = pred[j];
      }
    }
  int it = 0, step = 1;
  while (kg < n) {
    for (int i = 1; i <= n; i++) d[it][i] = g[pz[i]];
    it++;
    int nkg = 0;
    int beg = 1;
    while (beg <= n) {
      int end = beg;
      while (end + 1 <= n && g[end + 1] == g[beg]) {
        end++;
      }
      for (int i = beg; i <= end; i++) {
        int p = a[i] + step;
        t[i] = make_pair((p > n ? 0 : g[pz[p]]), a[i]);
      }
      sort(t + beg, t + end + 1);
      for (int i = beg; i <= end; i++) {
        if (i == beg || t[i].first != t[i - 1].first) {
          nkg++;
        }
        nna[i] = t[i].second;
        ng[i] = nkg;
      }
      beg = end + 1;
    }
    kg = nkg;
    for (int i = 1; i <= n; i++) {
      a[i] = nna[i];
      g[i] = ng[i];
      pz[a[i]] = i;
    }
    step <<= 1;
  }
  for (int i = 1; i <= n - 1; i++) {
    int v = 0;
    for (int j = it - 1; j >= 0; j--)
      if (a[i] + v <= n && a[i + 1] + v <= n && d[j][a[i] + v] == d[j][a[i + 1] + v]) {
        v += (1 << j);
      }
    lcp[i] = v;
  }
  for (int j = 0; j < 3; j++) {
    sum[0][j] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      sum[i][j] = sum[i - 1][j];
    }
    if (type[a[i]] != -1) {
      sum[i][type[a[i]]]++;
    }
  }
  for (int i = 0; i <= n; i++) {
    last[i] = 0;
  }
  for (int i = 1; i <= n - 1; i++) {
    pred[i] = last[lcp[i]];
    last[lcp[i]] = i;
  }
  for (int i = 0; i <= n; i++) {
    pr[i] = i - 1;
    ne[i] = i + 1;
  }
  int ans = 0;
  for (int word = n - 1; word >= 1; word--) {
    int j = last[word];
    while (j > 0) {
      subtr(ans, sum[j], sum[pr[j]]);
      subtr(ans, sum[ne[j]], sum[j]);
      add(ans, sum[ne[j]], sum[pr[j]]);
      pr[ne[j]] = pr[j];
      ne[pr[j]] = ne[j];
      j = pred[j];
    }
    result[word] = ans;
  }
  int len = min(min(na, nb), nc);
  for (int i = 1; i < len; i++) {
    printf("%d ", result[i]);
  }
  printf("%d\n", result[len]);
  return 0;
}