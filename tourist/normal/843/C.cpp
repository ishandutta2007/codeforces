#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

vector <int> st;
int pv[N], sz[N];
vector <int> g[N];
vector <int> jobs[N];
int depth[N];

bool flag;

void dfs(int v, int pr) {
  st.push_back(v);
  pv[v] = pr;
  sz[v] = 1;
  for (int u : g[v]) {
    if (u == pr) {
      continue;
    }
    depth[u] = depth[v] + 1;
    dfs(u, v);
    sz[v] += sz[u];
  }
  if (flag && depth[v] >= 3) {
    jobs[st[1]].push_back(v);
  }
  st.pop_back();
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  flag = false;
  dfs(0, -1);
  vector <int> roots;
  for (int i = 0; i < n; i++) {
    int outer = n - sz[i];
    if (outer > n / 2) {
      continue;
    }
    bool ok = true;
    for (int j : g[i]) {
      if (j == pv[i]) {
        continue;
      }
      if (sz[j] > n / 2) {
        ok = false;
        break;
      }
    }
    if (ok) {
      roots.push_back(i);
    }
  }
  assert(!roots.empty());
  flag = true;
  if ((int) roots.size() == 1) {
    depth[roots[0]] = 0;
    dfs(roots[0], -1);
  } else {
    depth[roots[0]] = depth[roots[1]] = 0;
    dfs(roots[0], roots[1]);
    dfs(roots[1], roots[0]);
  }
  vector < pair <int, pair <int, int> > > res;
  for (int i = 0; i < n; i++) {
    if (jobs[i].empty()) {
      continue;
    }
    int at = i;
    for (int &v : jobs[i]) {
      res.emplace_back(pv[i], make_pair(at, v));
      res.emplace_back(v, make_pair(pv[v], i));
      at = v;
    }
    res.emplace_back(pv[i], make_pair(at, i));
  }
  int cnt = res.size();
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++) {
    printf("%d %d %d\n", res[i].first + 1, res[i].second.first + 1, res[i].second.second + 1);
  }
  return 0;
}