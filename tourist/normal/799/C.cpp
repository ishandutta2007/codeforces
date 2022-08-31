#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int pref[N], a[N], b[N];
char c[N];

int solve(vector < pair <int, int> > z, int b) {
  sort(z.begin(), z.end());
  int cnt = z.size();
  if (cnt < 2) {
    return 0;
  }
  pref[0] = 0;
  for (int i = 0; i < cnt; i++) {
    pref[i + 1] = max(pref[i], z[i].second);
  }
  int i = 0;
  int res = 0;
  for (int j = cnt - 1; j >= 0; j--) {
    while (i < j && z[i].first + z[j].first <= b) {
      i++;
    }
    i = min(i, j);
    if (i > 0) {
      res = max(res, pref[i] + z[j].second);
    }
  }
  return res;
}

int main() {
  int n, C, D;
  scanf("%d %d %d", &n, &C, &D);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", a + i, b + i);
    c[i] = getchar();
    while (c[i] != 'C' && c[i] != 'D') {
      c[i] = getchar();
    }
  }
  int ans = 0;
  {
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      if (c[i] == 'C' && b[i] <= C) {
        x = max(x, a[i]);
      }
    }
    for (int i = 0; i < n; i++) {
      if (c[i] == 'D' && b[i] <= D) {
        y = max(y, a[i]);
      }
    }
    if (x > 0 && y > 0) {
      ans = max(ans, x + y);
    }
  }
  {
    vector < pair <int, int> > z;
    for (int i = 0; i < n; i++) {
      if (c[i] == 'C') {
        z.push_back(make_pair(b[i], a[i]));
      }
    }
    ans = max(ans, solve(z, C));
  }
  {
    vector < pair <int, int> > z;
    for (int i = 0; i < n; i++) {
      if (c[i] == 'D') {
        z.push_back(make_pair(b[i], a[i]));
      }
    }
    ans = max(ans, solve(z, D));
  }
  printf("%d\n", ans);
  return 0;
}