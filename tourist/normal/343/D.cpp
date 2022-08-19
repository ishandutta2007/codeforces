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

const int N = 500010;

int pz[N], pv[N], fin[N];
int s[N], val[N];
int kw, w[N];
int ss[2 * N], ff[2 * N], pred[2 * N], last[N];

void dfs(int v, int pr) {
  w[++kw] = v;
  pz[v] = kw;
  int j = last[v];
  while (j > 0) {
    if (ff[j] != pr) {
      pv[ff[j]] = v;
      dfs(ff[j], v);
    }
    j = pred[j];
  }
  fin[v] = kw;
}

int main() {
  int n;
  scanf("%d", &n);
  int m = n - 1;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", ss + i, ff + i);
    ss[i + m] = ff[i];
    ff[i + m] = ss[i];
  }
  for (int i = 1; i <= n; i++) last[i] = 0;
  for (int i = 1; i <= m + m; i++) {
    pred[i] = last[ss[i]];
    last[ss[i]] = i;
  }
  kw = 0;
  dfs(1, 0);
  for (int i = 1; i <= n; i++) s[i] = 0;
  for (int i = 1; i <= n; i++) {
    s[i]++;
    int j = (i | (i - 1)) + 1;
    if (j <= n) s[j] += s[i];
    val[i] = 1;
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int com, v;
    scanf("%d %d", &com, &v);
    if (com == 1) {
      int sum = 0;
      int x = pz[v] - 1;
      while (x > 0) {
        sum += s[x];
        x &= x - 1;
      }
      int cur = 0;
      x = fin[v];
      while (x > 0) {
        cur += s[x];
        x &= x - 1;
      }
      if (cur == sum) continue;
      int last = pz[v] - 1;
      while (cur > sum) {
        int ll = last + 1, rr = fin[v];
        while (ll < rr) {
          int mid = (ll + rr) >> 1;
          x = mid;
          int q = 0;
          while (x > 0) {
            q += s[x];
            x &= x - 1;
          }
          if (q > sum) rr = mid;
          else ll = mid + 1;
        }
        x = ll;
        val[x] = 0;
        while (x <= n) {
          s[x]--;
          x = (x | (x - 1)) + 1;
        }
        last = ll;
        cur--;
      }
      if (v != 1) {
        int x = pz[pv[v]];
        if (val[x] == 0) {
          val[x] = 1;
          while (x <= n) {
            s[x]++;
            x = (x | (x - 1)) + 1;
          }
        }
      }
    } else
    if (com == 2) {
      if (val[pz[v]] == 0) {
        int x = pz[v];
        val[x] = 1;
        while (x <= n) {
          s[x]++;
          x = (x | (x - 1)) + 1;
        }
      }
    } else {
      int sum = 0;
      int x = fin[v];
      while (x > 0) {
        sum += s[x];
        x &= x - 1;
      }
      x = pz[v] - 1;
      while (x > 0) {
        sum -= s[x];
        x &= x - 1;
      }
      if (sum > 0) printf("0\n");
      else printf("1\n");
    }
  }
  return 0;
}