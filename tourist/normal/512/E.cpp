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
#include <memory.h>
#include <cassert>

using namespace std;

const int N = 2010;

int n;
vector < pair <int, int> > ret;
bool have[N];
int a[N], b[N], c[N], d[N];
int mark[N];

void solve(vector <int> v) {
  int sz = v.size();
  if (sz <= 3) {
    return;
  }
  for (int i = 0; i < n; i++) {
    have[i] = false;
  }
  for (int i = 0; i < sz; i++) {
    have[v[i]] = true;
  }
  int mx = -1, x = -1, y = -1;
  for (int i = 0; i < n - 3; i++) {
    if (have[c[i]] && have[d[i]]) {
      int cnt = 0;
      int cur = c[i];
      while (cur != d[i]) {
        cnt += have[cur];
        cur = (cur + 1) % n;
      }
      if (cnt > sz - cnt) {
        cnt = sz - cnt;
      }
      if (cnt > mx) {
        mx = cnt;
        x = c[i];
        y = d[i];
      }
    }
  }
  if (x > y) {
    swap(x, y);
  }
  vector < pair < int, int > > inter;
  for (int i = 0; i < n - 3; i++) {
    if (have[a[i]] && have[b[i]]) {
      int xx = a[i];
      int yy = b[i];
      if (xx > yy) {
        swap(xx, yy);
      }
      if (x <= xx && yy <= y) {
        continue;
      }
      if (xx <= x && y <= yy) {
        continue;
      }
      if (yy <= x || y <= xx) {
        continue;
      }
      int dist;
      if (x < yy && yy < y) {
        dist = (yy - x) + (x - xx);
      } else {
        dist = (xx - x) + (x + n - yy);
      }
      inter.push_back(make_pair(dist, i));
    }
  }
  sort(inter.begin(), inter.end());
  int cc = inter.size();
  for (int id = 0; id < cc; id++) {
    int xx = a[inter[id].second];
    int yy = b[inter[id].second];
    ret.push_back(make_pair(xx, yy));
    for (int i = 0; i < sz; i++) {
      mark[v[i]] = 0;
    }
    for (int i = 0; i < n - 3; i++) {
      if (have[a[i]] && have[b[i]]) {
        if (a[i] == xx || a[i] == yy) {
          mark[b[i]]++;
        }
        if (b[i] == xx || b[i] == yy) {
          mark[a[i]]++;
        }
      }
    }
    mark[(xx + 1) % n]++;
    mark[(xx + n - 1) % n]++;
    mark[(yy + 1) % n]++;
    mark[(yy + n - 1) % n]++;
    int to = -1;
    for (int i = 0; i < sz; i++) {
      if (mark[v[i]] == 2 && v[i] != x && v[i] != xx && v[i] != yy) {
        to = v[i];
        break;
      }
    }
    a[inter[id].second] = x;
    b[inter[id].second] = to;
  }
  vector <int> other1, other2;
  int cur = x;
  while (true) {
    if (have[cur]) {
      other1.push_back(cur);
    }
    if (cur == y) {
      break;
    }
    cur = (cur + 1) % n;
  }
  cur = y;
  while (true) {
    if (have[cur]) {
      other2.push_back(cur);
    }
    if (cur == x) {
      break;
    }
    cur = (cur + 1) % n;
  }
  solve(other1);
  solve(other2);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 3; i++) {
    scanf("%d %d", a + i, b + i);
    a[i]--; b[i]--;
  }
  for (int i = 0; i < n - 3; i++) {
    scanf("%d %d", c + i, d + i);
    c[i]--; d[i]--;
  }
  vector <int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(i);
  }
  ret.clear();
  solve(v);
//  for (int i = 0; i < n - 3; i++) cout << a[i] << " " << b[i] << endl;
//  cout << endl;
//  for (int i = 0; i < n - 3; i++) cout << c[i] << " " << d[i] << endl;
  int sz = ret.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    printf("%d %d\n", ret[i].first + 1, ret[i].second + 1);
  }
  return 0;
}