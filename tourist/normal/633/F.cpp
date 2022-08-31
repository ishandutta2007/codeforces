#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

vector <int> g[N];
long long down[N], best[N];
int cost[N];

long long ans;

void dfs(int v, int pr) {
  int sz = g[v].size();
  vector <long long> values;
  best[v] = 0;
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (u == pr) {
      continue;
    }
    dfs(u, v);
    values.push_back(down[u]);
    best[v] = max(best[v], best[u]);
  }
  int cnt = values.size();
  long long max1 = 0, max2 = 0;
  for (int i = 0; i < cnt; i++) {
    if (values[i] > max1) {
      max2 = max1;
      max1 = values[i];
    } else {
      if (values[i] > max2) {
        max2 = values[i];
      }
    }
  }
  best[v] = max(best[v], max1 + max2 + cost[v]);
  down[v] = max1 + cost[v];
  ans = max(ans, best[v]);
}

void solve(int v, int pr, long long up) {
  up += cost[v];
  vector <int> children;
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (u == pr) {
      continue;
    }
    children.push_back(u);
  }
  int cnt = children.size();
  if (cnt == 0) {
    return;
  }
  vector <long long> prefbest(cnt + 1);
  vector <long long> sufbest(cnt + 1);
  prefbest[0] = 0;
  for (int i = 0; i < cnt; i++) {
    prefbest[i + 1] = max(prefbest[i], best[children[i]]);
  }
  sufbest[cnt] = 0;
  for (int i = cnt - 1; i >= 0; i--) {
    sufbest[i] = max(sufbest[i + 1], best[children[i]]);
  }
  vector <long long> prefdown(cnt + 1);
  vector <long long> sufdown(cnt + 1);
  vector <long long> prefdow2(cnt + 1);
  vector <long long> sufdow2(cnt + 1);
  prefdown[0] = 0;
  prefdow2[0] = 0;
  for (int i = 0; i < cnt; i++) {
    prefdown[i + 1] = prefdown[i];
    prefdow2[i + 1] = prefdow2[i];
    long long z = down[children[i]];
    if (z > prefdown[i + 1]) {
      prefdow2[i + 1] = prefdown[i + 1];
      prefdown[i + 1] = z;
    } else {
      if (z > prefdow2[i + 1]) {
        prefdow2[i + 1] = z;
      }
    }
  }
  sufdown[cnt] = 0;
  sufdow2[cnt] = 0;
  for (int i = cnt - 1; i >= 0; i--) {
    sufdown[i] = sufdown[i + 1];
    sufdow2[i] = sufdow2[i + 1];
    long long z = down[children[i]];
    if (z > sufdown[i]) {
      sufdow2[i] = sufdown[i];
      sufdown[i] = z;
    } else {
      if (z > sufdow2[i]) {
        sufdow2[i] = z;
      }
    }
  }
  for (int i = 0; i < cnt; i++) {
    long long cur = max(prefbest[i], sufbest[i + 1]);
    cur = max(cur, up + max(prefdown[i], sufdown[i + 1]));
    cur = max(cur, cost[v] + prefdown[i] + sufdown[i + 1]);
    cur = max(cur, cost[v] + prefdown[i] + prefdow2[i]);
    cur = max(cur, cost[v] + sufdown[i + 1] + sufdow2[i + 1]);
    cur += best[children[i]];
    ans = max(ans, cur);
  }
  for (int i = 0; i < cnt; i++) {
    int u = children[i];
    long long new_up = up;
    new_up = max(new_up, max(prefdown[i], sufdown[i + 1]) + cost[v]);
    solve(u, v, new_up);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", cost + i);
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int foo, bar;
    scanf("%d %d", &foo, &bar);
    foo--; bar--;
    g[foo].push_back(bar);
    g[bar].push_back(foo);
  }
  dfs(0, -1);
  ans = 0;
  solve(0, -1, 0);
  cout << ans << endl;
  return 0;
}