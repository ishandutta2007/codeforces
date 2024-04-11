#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

bool was[N];
int color[N];
vector < pair <int, int> > g[N];
vector <int> comp;

void go(int v, int into, int root) {
  was[v] = true;
  color[v] = root;
  comp.push_back(v);
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j].first;
    if (was[u]) {
      continue;
    }
    int w = g[v][j].second;
    int new_root = into ^ root ^ w;
    go(u, into, new_root);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--; y--;
    char z = getchar();
    while (z != 'B' && z != 'R') {
      z = getchar();
    }
    g[x].push_back(make_pair(y, z == 'B'));
    g[y].push_back(make_pair(x, z == 'B'));
  }
  vector <int> best_res;
  bool any_res = false;
  for (int into = 0; into < 2; into++) {
    for (int i = 0; i < n; i++) {
      was[i] = false;
    }
    bool bad = false;
    vector <int> res;
    for (int i = 0; i < n; i++) {
      if (was[i]) {
        continue;
      }
      vector <int> best;
      bool any = false;
      for (int root = 0; root < 2; root++) {
        comp.clear();
        go(i, into, root);
        bool ok = true;
        int z = -1;
        for (int j = 0; j < (int) comp.size(); j++) {
          int u = comp[j];
          for (int q = 0; q < (int) g[u].size(); q++) {
            int v = g[u][q].first;
            int w = g[u][q].second;
            int cur = color[u] ^ color[v] ^ w;
            if (z == -1) {
              z = cur;
            } else {
              if (cur != z) {
                ok = false;
                break;
              }
            }
          }
        }
        if (ok) {
          vector <int> cand;
          for (int j = 0; j < (int) comp.size(); j++) {
            int u = comp[j];
            if (color[u]) {
              cand.push_back(u);
            }
          }
          if (!any || cand.size() < best.size()) {
            best = cand;
            any = true;
          }
        }
        if (root == 0) {
          for (int j = 0; j < (int) comp.size(); j++) {
            int u = comp[j];
            was[u] = false;
          }
        }
      }
      if (!any) {
        bad = true;
        break;
      }
      for (int j = 0; j < (int) best.size(); j++) {
        res.push_back(best[j]);
      }
    }
    if (!bad) {
      if (!any_res || res.size() < best_res.size()) {
        best_res = res;
        any_res = true;
      }
    }
  }
  if (!any_res) {
    puts("-1");
    return 0;
  }
  sort(best_res.begin(), best_res.end());
  int sz = best_res.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", best_res[i] + 1);
  }
  printf("\n");
  return 0;
}