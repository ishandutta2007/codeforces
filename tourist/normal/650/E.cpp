#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int p[N];

inline int find_set(int x) {
  if (x != p[x]) {
    p[x] = find_set(p[x]);
  }
  return p[x];
}

vector < pair <int, int> > edges[N];

inline void unite(int x, int y) {
  x = find_set(x);
  y = find_set(y);
  if (x == y) {
    return;
  }
  p[x] = y;
  if (edges[x].size() > edges[y].size()) {
    swap(edges[x], edges[y]);
  }
  while (!edges[x].empty()) {
    edges[y].push_back(edges[x].back());
    edges[x].pop_back();
  }
}

vector < pair <int, int> > g[N];
bool rem[N], add[N];
bool done[N];
int bx[N], by[N];

inline void dfs(int v, int pr) {
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j].first;
    if (u == pr) {
      continue;
    }
    dfs(u, v);
    int id = g[v][j].second;
    if (!rem[id]) {
      unite(u, v);
      continue;
    }
    pair <int, int> e = edges[u].back();
    while (done[e.second]) {
      edges[u].pop_back();
      e = edges[u].back();
    }
    done[e.second] = true;
    printf("%d %d %d %d\n", u + 1, v + 1, bx[e.second] + 1, by[e.second] + 1);
    edges[u].pop_back();
    unite(u, e.first);
  }
}

int ax[N], ay[N];
pair < pair <int, int>, int > ev[2 * N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", ax + i, ay + i);
    ax[i]--; ay[i]--;
    if (ax[i] > ay[i]) {
      swap(ax[i], ay[i]);
    }
    ev[i] = make_pair(make_pair(ax[i], ay[i]), i);
    rem[i] = false;
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", bx + i, by + i);
    bx[i]--; by[i]--;
    if (bx[i] > by[i]) {
      swap(bx[i], by[i]);
    }
    ev[n - 1 + i] = make_pair(make_pair(bx[i], by[i]), ~i);
    add[i] = false;
  }
  sort(ev, ev + n - 1 + n - 1);
  int ans = 0;
  for (int i = n - 1 + n - 1 - 1; i >= 0; i--) {
    if (i > 0 && ev[i].first == ev[i - 1].first) {
      i--;
      continue;
    }
    int x = ev[i].second;
    if (x >= 0) {
      rem[x] = true;
      ans++;
    } else {
      add[~x] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    g[ax[i]].push_back(make_pair(ay[i], i));
    g[ay[i]].push_back(make_pair(ax[i], i));
  }
  for (int i = 0; i < n; i++) {
    edges[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    if (!add[i]) {
      continue;
    }
    done[i] = false;
    edges[bx[i]].push_back(make_pair(by[i], i));
    edges[by[i]].push_back(make_pair(bx[i], i));
  }
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  printf("%d\n", ans);
  dfs(0, -1);
  return 0;
}