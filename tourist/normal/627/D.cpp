#include <bits/stdc++.h>

using namespace std;

struct DP {
  int sum;
  int mx;
};

inline DP join(DP &a, DP &b) {
  DP c;
  c.sum = a.sum + b.sum;
  c.mx = max(a.mx, b.mx);
  return c;
}

const int N = 200010;

vector <int> g[N];
int total[N];
int f[N], dp[N];
bool good[N];
int a[N];
int n;

void dfs(int v, int pr) {
  int sz = g[v].size();
  total[v] = 1;
  int sum = 0, mx = 0;
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (u == pr) {
      continue;
    }
    dfs(u, v);
    total[v] += total[u];
    if (f[u] == total[u]) {
      sum += f[u];
    } else {
      mx = max(mx, f[u]);
    }
  }
  f[v] = sum + mx + 1;
  if (!good[v]) {
    f[v] = 0;
  }
}

void solve(int v, int pr, int up) {
  int sz = g[v].size();
  vector <int> children;
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (u == pr) {
      continue;
    }
    children.push_back(u);
  }
  int cnt = children.size();
  int sum = 0, mx = 0;
  for (int j = 0; j < cnt; j++) {
    int u = children[j];
    if (f[u] == total[u]) {
      sum += f[u];
    } else {
      mx = max(mx, f[u]);
    }
  }
  if (up == n - total[v]) {
    sum += up;
  } else {
    mx = max(mx, up);
  }
  dp[v] = sum + mx + 1;
  if (!good[v]) {
    dp[v] = 0;
  }
  if (cnt == 0) {
    return;
  }
  vector <DP> pref(cnt + 1);
  vector <DP> suf(cnt + 1);
  pref[0] = {0, 0};
  for (int j = 0; j < cnt; j++) {
    int u = children[j];
    pref[j + 1] = pref[j];
    if (f[u] == total[u]) {
      pref[j + 1].sum += f[u];
    } else {
      pref[j + 1].mx = max(pref[j + 1].mx, f[u]);
    }
  }
  suf[cnt] = {0, 0};
  for (int j = cnt - 1; j >= 0; j--) {
    int u = children[j];
    suf[j] = suf[j + 1];
    if (f[u] == total[u]) {
      suf[j].sum += f[u];
    } else {
      suf[j].mx = max(suf[j].mx, f[u]);
    }
  }
  for (int j = 0; j < cnt; j++) {
    int u = children[j];
    DP z = join(pref[j], suf[j + 1]);
    if (up == n - total[v]) {
      z.sum += up;
    } else {
      z.mx = max(z.mx, up);
    }
    int new_up = z.sum + z.mx + 1;
    if (!good[v]) {
      new_up = 0;
    }
    solve(u, v, new_up);
  }
}

int main() {
  int k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int low = 0, high = 1000010;
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    for (int j = 0; j < n; j++) {
      good[j] = (a[j] >= mid);
    }
    dfs(0, -1);
    solve(0, -1, 0);
    int best = 0;
    for (int j = 0; j < n; j++) {
      best = max(best, dp[j]);
    }
    if (best >= k) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  printf("%d\n", low);
  return 0;
}