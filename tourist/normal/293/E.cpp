#include <cstring>
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
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 444444;

int ss[N], ff[N], dd[N], pred[N], last[N], s[N], num[N], l[N], w[N], cnt[N];
vector < pair <int, int> > e;
bool good[N];
int n, ml, mw, m;
long long ans;

void go(int v, int pr, int len, int wei) {
  l[m] = len;
  w[m] = wei;
  m++;
  cnt[v] = 1;
  int j = last[v];
  while (j > 0) {
    if (good[num[j]] && ff[j] != pr) {
      go(ff[j], v, len+1, wei+dd[j]);
      cnt[v] += cnt[ff[j]];
    }
    j = pred[j];
  }
}

int findsum(int x) {
  x++;
  int v = 0;
  while (x > 0) {
    v += s[x];
    x &= x-1;
  }
  return v;
}

void modify(int x, int v) {
  x++;
  while (x <= n+1) {
    s[x] += v;
    x = (x | (x-1))+1;
  }
}

void solve(int v) {
  m = 0;
  go(v, 0, 0, 0);
  int change = 1, pr = 0;
  int total = cnt[v];
  while (change) {
    change = 0;
    int j = last[v];
    while (j > 0) {
      if (good[num[j]] && ff[j] != pr)
        if (cnt[ff[j]] > total/2) {
          pr = v;
          v = ff[j];
          change = 1;
          break;
        }
      j = pred[j];
    }
  }
  m = 0;
  go(v, 0, 0, 0);
  e.clear();
  for (int i=0;i<m;i++) {
    e.push_back(make_pair(w[i], ~l[i]));
    if (w[i] <= mw && l[i] <= ml) {
      e.push_back(make_pair(mw-w[i], ml-l[i]));
    }
  }
  sort(e.begin(), e.end());
  int sz = e.size();
  for (int i=0;i<sz;i++) {
    if (e[i].second >= 0) {
      ans += findsum(e[i].second);
    } else {
      modify(~e[i].second, 1);
    }
  }
  for (int i=0;i<sz;i++) {
    if (e[i].second < 0) {
      modify(~e[i].second, -1);
    }
  }
  vector <int> desc;
  int j = last[v];
  while (j > 0) {
    if (good[num[j]]) {
      good[num[j]] = false;
      desc.push_back(j);
    }
    j = pred[j];
  }
  for (int z=0;z<desc.size();z++) {
    m = 0;
    go(ff[desc[z]], 0, 1, dd[desc[z]]);
    e.clear();
    for (int i=0;i<m;i++) {
      e.push_back(make_pair(w[i], ~l[i]));
      if (w[i] <= mw && l[i] <= ml) {
        e.push_back(make_pair(mw-w[i], ml-l[i]));
      }
    }
    sort(e.begin(), e.end());
    int sz = e.size();
    for (int i=0;i<sz;i++) {
      if (e[i].second >= 0) {
        ans -= findsum(e[i].second);
      } else {
        modify(~e[i].second, 1);
      }
    }
    for (int i=0;i<sz;i++) {
      if (e[i].second < 0) {
        modify(~e[i].second, -1);
      }
    }
  }
  ans--;
  int ds = desc.size();
  for (int i=0;i<ds;i++) solve(ff[desc[i]]);
}

int main() {
  scanf("%d %d %d", &n, &ml, &mw);
  int m = n-1;
  for (int i=1;i<=m;i++) {
    scanf("%d %d", ss+i, dd+i);
    ff[i] = i+1;
    ss[i+m] = ff[i];
    ff[i+m] = ss[i];
    dd[i+m] = dd[i];
    num[i+m] = i;
    num[i] = i;
    good[i] = true;
  }
  for (int i=1;i<=n;i++) last[i] = 0;
  for (int i=1;i<=m+m;i++) {
    pred[i] = last[ss[i]];
    last[ss[i]] = i;
  }
  for (int i=1;i<=n;i++) s[i] = 0;
  ans = 0;
  solve(1);
  cout << ans / 2 << endl;
  return 0;
}